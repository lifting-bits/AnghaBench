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
struct cvmx_shmem_dscptr {scalar_t__ owner; } ;

/* Variables and functions */
 scalar_t__ CVMX_SHMEM_OWNER_NONE ; 

__attribute__((used)) static struct cvmx_shmem_dscptr *__cvmx_shmem_smdr_is_free(struct cvmx_shmem_dscptr* dscptr, void *nouse)
{
    if (dscptr->owner == CVMX_SHMEM_OWNER_NONE)
        return dscptr;
    else
        return NULL;
}