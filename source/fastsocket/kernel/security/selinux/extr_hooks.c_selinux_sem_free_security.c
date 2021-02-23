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
struct sem_array {int /*<<< orphan*/  sem_perm; } ;

/* Variables and functions */
 int /*<<< orphan*/  ipc_free_security (int /*<<< orphan*/ *) ; 

__attribute__((used)) static void selinux_sem_free_security(struct sem_array *sma)
{
	ipc_free_security(&sma->sem_perm);
}