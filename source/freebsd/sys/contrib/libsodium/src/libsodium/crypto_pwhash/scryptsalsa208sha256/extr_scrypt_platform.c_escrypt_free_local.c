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
typedef  int /*<<< orphan*/  escrypt_local_t ;

/* Variables and functions */
 int free_region (int /*<<< orphan*/ *) ; 

int
escrypt_free_local(escrypt_local_t *local)
{
    return free_region(local);
}