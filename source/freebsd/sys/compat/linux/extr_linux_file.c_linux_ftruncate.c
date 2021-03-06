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
struct linux_ftruncate_args {int /*<<< orphan*/  length; int /*<<< orphan*/  fd; } ;

/* Variables and functions */
 int kern_ftruncate (struct thread*,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 

int
linux_ftruncate(struct thread *td, struct linux_ftruncate_args *args)
{

	return (kern_ftruncate(td, args->fd, args->length));
}