#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_5__   TYPE_2__ ;
typedef  struct TYPE_4__   TYPE_1__ ;

/* Type definitions */
typedef  TYPE_2__* vnode_t ;
typedef  scalar_t__ user_ssize_t ;
typedef  int /*<<< orphan*/  uguard ;
struct vfs_context {int /*<<< orphan*/  vc_ucred; } ;
struct proc {int dummy; } ;
struct guarded_pwrite_np_args {int fd; int offset; int /*<<< orphan*/  nbyte; int /*<<< orphan*/  buf; int /*<<< orphan*/  guard; } ;
struct guarded_fileproc {int dummy; } ;
struct fileproc {int f_flag; scalar_t__ f_type; TYPE_1__* f_fglob; } ;
typedef  int off_t ;
typedef  int /*<<< orphan*/  guardid_t ;
struct TYPE_5__ {int v_flag; } ;
struct TYPE_4__ {scalar_t__ fg_data; int /*<<< orphan*/  fg_cred; } ;

/* Variables and functions */
 int /*<<< orphan*/  AUDIT_ARG (int,int) ; 
 int BSDDBG_CODE (int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  DBG_BSD_SC_EXTENDED_INFO ; 
 int DBG_FUNC_NONE ; 
 scalar_t__ DTYPE_VNODE ; 
 int EBADF ; 
 int EINVAL ; 
 int ENXIO ; 
 int ESPIPE ; 
 int /*<<< orphan*/  FOF_OFFSET ; 
 int FWRITE ; 
 struct fileproc* GFP_TO_FP (struct guarded_fileproc*) ; 
 int /*<<< orphan*/  KERNEL_DEBUG_CONSTANT (int,int,int /*<<< orphan*/ ,unsigned int,unsigned int,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  SYS_guarded_pwrite_np ; 
 int VISTTY ; 
 int copyin (int /*<<< orphan*/ ,int /*<<< orphan*/ *,int) ; 
 int dofilewrite (struct vfs_context*,struct fileproc*,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int,int /*<<< orphan*/ ,scalar_t__*) ; 
 int /*<<< orphan*/  fp_drop (struct proc*,int,struct fileproc*,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  fp_drop_written (struct proc*,int,struct fileproc*) ; 
 int fp_lookup_guarded (struct proc*,int,int /*<<< orphan*/ ,struct guarded_fileproc**,int /*<<< orphan*/ ) ; 
 struct vfs_context* vfs_context_current () ; 
 scalar_t__ vnode_isfifo (TYPE_2__*) ; 

int
 guarded_pwrite_np(struct proc *p, struct guarded_pwrite_np_args *uap, user_ssize_t *retval)
 {
	struct fileproc *fp;
	int error; 
	int fd = uap->fd;
	vnode_t vp  = (vnode_t)0;
	guardid_t uguard;
	struct guarded_fileproc *gfp;
	bool wrote_some = false;

	AUDIT_ARG(fd, fd);

	if ((error = copyin(uap->guard, &uguard, sizeof (uguard))) != 0)
		return (error);

	error = fp_lookup_guarded(p, fd, uguard, &gfp, 0);
	if (error)
		return(error);

	fp = GFP_TO_FP(gfp);
	if ((fp->f_flag & FWRITE) == 0) {
		error = EBADF;
	} else {
		struct vfs_context context = *vfs_context_current();
		context.vc_ucred = fp->f_fglob->fg_cred;

		if (fp->f_type != DTYPE_VNODE) {
			error = ESPIPE;
			goto errout;
		}
		vp = (vnode_t)fp->f_fglob->fg_data;
		if (vnode_isfifo(vp)) {
			error = ESPIPE;
			goto errout;
		} 
		if ((vp->v_flag & VISTTY)) {
			error = ENXIO;
			goto errout;
		}
		if (uap->offset == (off_t)-1) {
			error = EINVAL;
			goto errout;
		}

		error = dofilewrite(&context, fp, uap->buf, uap->nbyte,
			uap->offset, FOF_OFFSET, retval);
		wrote_some = *retval > 0;
	}
errout:
	if (wrote_some)
	        fp_drop_written(p, fd, fp);
	else
	        fp_drop(p, fd, fp, 0);

	KERNEL_DEBUG_CONSTANT((BSDDBG_CODE(DBG_BSD_SC_EXTENDED_INFO, SYS_guarded_pwrite_np) | DBG_FUNC_NONE),
	      uap->fd, uap->nbyte, (unsigned int)((uap->offset >> 32)), (unsigned int)(uap->offset), 0);
	
        return(error);
}