#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */

/* Type definitions */
struct vnode {int dummy; } ;
struct ucred {int dummy; } ;
struct nfsvattr {int dummy; } ;
struct nfsrvsetattrdsdorpc {scalar_t__ done; scalar_t__ inprog; int err; int /*<<< orphan*/  tsk; struct nfsvattr na; int /*<<< orphan*/ * p; struct ucred* cred; struct vnode* vp; struct nfsmount* nmp; int /*<<< orphan*/  fh; } ;
struct nfsmount {int dummy; } ;
typedef  int /*<<< orphan*/  fhandle_t ;
typedef  int /*<<< orphan*/  NFSPROC_T ;

/* Variables and functions */
 int EIO ; 
 int /*<<< orphan*/  M_TEMP ; 
 int /*<<< orphan*/  M_WAITOK ; 
 int /*<<< orphan*/  NFSBCOPY (int /*<<< orphan*/ *,int /*<<< orphan*/ *,int) ; 
 int /*<<< orphan*/  NFSD_DEBUG (int,char*,...) ; 
 int /*<<< orphan*/  PVFS ; 
 int /*<<< orphan*/  free (struct nfsrvsetattrdsdorpc*,int /*<<< orphan*/ ) ; 
 int hz ; 
 struct nfsrvsetattrdsdorpc* malloc (int,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int nfs_pnfsio (int /*<<< orphan*/ ,struct nfsrvsetattrdsdorpc*) ; 
 scalar_t__ nfs_pnfsiothreads ; 
 scalar_t__ nfsds_failerr (int) ; 
 int nfsrv_setattrdsdorpc (int /*<<< orphan*/ *,struct ucred*,int /*<<< orphan*/ *,struct vnode*,struct nfsmount*,struct nfsvattr*,struct nfsvattr*) ; 
 int nfsrv_setextattr (struct vnode*,struct nfsvattr*,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  start_setattrdsdorpc ; 
 int /*<<< orphan*/  tsleep (int /*<<< orphan*/ *,int /*<<< orphan*/ ,char*,int) ; 

__attribute__((used)) static int
nfsrv_setattrdsrpc(fhandle_t *fhp, struct ucred *cred, NFSPROC_T *p,
    struct vnode *vp, struct nfsmount **nmpp, int mirrorcnt,
    struct nfsvattr *nap, int *failposp)
{
	struct nfsrvsetattrdsdorpc *drpc, *tdrpc;
	struct nfsvattr na;
	int error, i, ret, timo;

	NFSD_DEBUG(4, "in nfsrv_setattrdsrpc\n");
	drpc = NULL;
	if (mirrorcnt > 1)
		tdrpc = drpc = malloc(sizeof(*drpc) * (mirrorcnt - 1), M_TEMP,
		    M_WAITOK);

	/*
	 * Do the setattr RPC for every DS, using a separate kernel process
	 * for every DS except the last one.
	 */
	error = 0;
	for (i = 0; i < mirrorcnt - 1; i++, tdrpc++) {
		tdrpc->done = 0;
		tdrpc->inprog = 0;
		NFSBCOPY(fhp, &tdrpc->fh, sizeof(*fhp));
		tdrpc->nmp = *nmpp;
		tdrpc->vp = vp;
		tdrpc->cred = cred;
		tdrpc->p = p;
		tdrpc->na = *nap;
		tdrpc->err = 0;
		ret = EIO;
		if (nfs_pnfsiothreads != 0) {
			ret = nfs_pnfsio(start_setattrdsdorpc, tdrpc);
			NFSD_DEBUG(4, "nfsrv_setattrdsrpc: nfs_pnfsio=%d\n",
			    ret);
		}
		if (ret != 0) {
			ret = nfsrv_setattrdsdorpc(fhp, cred, p, vp, *nmpp, nap,
			    &na);
			if (nfsds_failerr(ret) && *failposp == -1)
				*failposp = i;
			else if (error == 0 && ret != 0)
				error = ret;
		}
		nmpp++;
		fhp++;
	}
	ret = nfsrv_setattrdsdorpc(fhp, cred, p, vp, *nmpp, nap, &na);
	if (nfsds_failerr(ret) && *failposp == -1 && mirrorcnt > 1)
		*failposp = mirrorcnt - 1;
	else if (error == 0 && ret != 0)
		error = ret;
	if (error == 0)
		error = nfsrv_setextattr(vp, &na, p);
	NFSD_DEBUG(4, "nfsrv_setattrdsrpc: aft setextat=%d\n", error);
	tdrpc = drpc;
	timo = hz / 50;		/* Wait for 20msec. */
	if (timo < 1)
		timo = 1;
	for (i = 0; i < mirrorcnt - 1; i++, tdrpc++) {
		/* Wait for RPCs on separate threads to complete. */
		while (tdrpc->inprog != 0 && tdrpc->done == 0)
			tsleep(&tdrpc->tsk, PVFS, "srvsads", timo);
		if (nfsds_failerr(tdrpc->err) && *failposp == -1)
			*failposp = i;
		else if (error == 0 && tdrpc->err != 0)
			error = tdrpc->err;
	}
	free(drpc, M_TEMP);
	return (error);
}