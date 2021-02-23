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
struct eaccess_args {int /*<<< orphan*/  amode; int /*<<< orphan*/  path; } ;

/* Variables and functions */
 int /*<<< orphan*/  AT_EACCESS ; 
 int /*<<< orphan*/  AT_FDCWD ; 
 int /*<<< orphan*/  UIO_USERSPACE ; 
 int kern_accessat (struct thread*,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 

int
sys_eaccess(struct thread *td, struct eaccess_args *uap)
{

	return (kern_accessat(td, AT_FDCWD, uap->path, UIO_USERSPACE,
	    AT_EACCESS, uap->amode));
}