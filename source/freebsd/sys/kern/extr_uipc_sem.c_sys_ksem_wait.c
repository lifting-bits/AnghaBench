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
struct ksem_wait_args {int /*<<< orphan*/  id; } ;

/* Variables and functions */
 int kern_sem_wait (struct thread*,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ *) ; 

int
sys_ksem_wait(struct thread *td, struct ksem_wait_args *uap)
{

	return (kern_sem_wait(td, uap->id, 0, NULL));
}