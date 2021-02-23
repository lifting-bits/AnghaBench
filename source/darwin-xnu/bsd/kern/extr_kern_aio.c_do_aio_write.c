#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_7__   TYPE_3__ ;
typedef  struct TYPE_6__   TYPE_2__ ;
typedef  struct TYPE_5__   TYPE_1__ ;

/* Type definitions */
struct vfs_context {int /*<<< orphan*/  vc_ucred; int /*<<< orphan*/  vc_thread; } ;
struct fileproc {TYPE_1__* f_fglob; } ;
struct TYPE_6__ {int /*<<< orphan*/  aio_fildes; int /*<<< orphan*/  aio_offset; int /*<<< orphan*/  aio_nbytes; int /*<<< orphan*/  aio_buf; } ;
struct TYPE_7__ {TYPE_2__ aiocb; int /*<<< orphan*/  procp; int /*<<< orphan*/  returnval; int /*<<< orphan*/  thread; } ;
typedef  TYPE_3__ aio_workq_entry ;
struct TYPE_5__ {int fg_flag; int /*<<< orphan*/  fg_cred; } ;

/* Variables and functions */
 int EBADF ; 
 int FOF_OFFSET ; 
 int FOF_PCRED ; 
 int FWRITE ; 
 int O_APPEND ; 
 int dofilewrite (struct vfs_context*,struct fileproc*,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  fp_drop (int /*<<< orphan*/ ,int /*<<< orphan*/ ,struct fileproc*,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  fp_drop_written (int /*<<< orphan*/ ,int /*<<< orphan*/ ,struct fileproc*) ; 
 int fp_lookup (int /*<<< orphan*/ ,int /*<<< orphan*/ ,struct fileproc**,int /*<<< orphan*/ ) ; 

__attribute__((used)) static int
do_aio_write( aio_workq_entry *entryp )
{
	struct fileproc 		*fp;
	int				error, flags;
	struct vfs_context		context;

	if ( (error = fp_lookup(entryp->procp, entryp->aiocb.aio_fildes, &fp , 0)) )
		return(error);
	if ( (fp->f_fglob->fg_flag & FWRITE) == 0 ) {
		fp_drop(entryp->procp, entryp->aiocb.aio_fildes, fp, 0);
		return(EBADF);
	}

	flags = FOF_PCRED;
	if ( (fp->f_fglob->fg_flag & O_APPEND) == 0 ) {
		flags |= FOF_OFFSET;
	}

	context.vc_thread = entryp->thread;	/* XXX */
	context.vc_ucred = fp->f_fglob->fg_cred;

	/* NB: tell dofilewrite the offset, and to use the proc cred */
	error = dofilewrite(&context,
				fp,
				entryp->aiocb.aio_buf,
				entryp->aiocb.aio_nbytes,
				entryp->aiocb.aio_offset,
				flags,
				&entryp->returnval);

	if (entryp->returnval)
		fp_drop_written(entryp->procp, entryp->aiocb.aio_fildes, fp);
	else
		fp_drop(entryp->procp, entryp->aiocb.aio_fildes, fp, 0);

	return( error );

}