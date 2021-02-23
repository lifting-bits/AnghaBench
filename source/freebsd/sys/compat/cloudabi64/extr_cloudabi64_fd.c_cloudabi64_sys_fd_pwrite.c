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
struct uio {int dummy; } ;
struct thread {int dummy; } ;
struct cloudabi64_sys_fd_pwrite_args {int /*<<< orphan*/  offset; int /*<<< orphan*/  fd; int /*<<< orphan*/  iovs_len; int /*<<< orphan*/  iovs; } ;

/* Variables and functions */
 int /*<<< orphan*/  M_IOV ; 
 int /*<<< orphan*/  TO_PTR (int /*<<< orphan*/ ) ; 
 int cloudabi64_copyinuio (int /*<<< orphan*/ ,int /*<<< orphan*/ ,struct uio**) ; 
 int /*<<< orphan*/  free (struct uio*,int /*<<< orphan*/ ) ; 
 int kern_pwritev (struct thread*,int /*<<< orphan*/ ,struct uio*,int /*<<< orphan*/ ) ; 

int
cloudabi64_sys_fd_pwrite(struct thread *td,
    struct cloudabi64_sys_fd_pwrite_args *uap)
{
	struct uio *uio;
	int error;

	error = cloudabi64_copyinuio(TO_PTR(uap->iovs), uap->iovs_len, &uio);
	if (error != 0)
		return (error);
	error = kern_pwritev(td, uap->fd, uio, uap->offset);
	free(uio, M_IOV);
	return (error);
}