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
struct mkfifoat_args {int /*<<< orphan*/  mode; int /*<<< orphan*/  path; int /*<<< orphan*/  fd; } ;

/* Variables and functions */
 int /*<<< orphan*/  UIO_USERSPACE ; 
 int kern_mkfifoat (struct thread*,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 

int
sys_mkfifoat(struct thread *td, struct mkfifoat_args *uap)
{

	return (kern_mkfifoat(td, uap->fd, uap->path, UIO_USERSPACE,
	    uap->mode));
}