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
struct shmid_kernel {int /*<<< orphan*/ * label; } ;

/* Variables and functions */
 int /*<<< orphan*/  mac_sysv_shm_label_free (int /*<<< orphan*/ *) ; 

void
mac_sysvshm_label_destroy(struct shmid_kernel *shmsegptr)
{

	mac_sysv_shm_label_free(shmsegptr->label);
	shmsegptr->label = NULL;
}