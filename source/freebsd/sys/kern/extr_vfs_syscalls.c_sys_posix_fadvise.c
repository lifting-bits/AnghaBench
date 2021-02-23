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
struct thread {int dummy; } ;
struct posix_fadvise_args {int /*<<< orphan*/  advice; int /*<<< orphan*/  len; int /*<<< orphan*/  offset; int /*<<< orphan*/  fd; } ;

/* Variables and functions */
 int kern_posix_error (struct thread*,int) ; 
 int kern_posix_fadvise (struct thread*,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 

int
sys_posix_fadvise(struct thread *td, struct posix_fadvise_args *uap)
{
	int error;

	error = kern_posix_fadvise(td, uap->fd, uap->offset, uap->len,
	    uap->advice);
	return (kern_posix_error(td, error));
}