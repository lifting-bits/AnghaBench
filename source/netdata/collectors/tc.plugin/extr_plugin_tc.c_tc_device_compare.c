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
struct tc_device {scalar_t__ hash; int /*<<< orphan*/  id; } ;

/* Variables and functions */
 int strcmp (int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 

__attribute__((used)) static int tc_device_compare(void* a, void* b) {
    if(((struct tc_device *)a)->hash < ((struct tc_device *)b)->hash) return -1;
    else if(((struct tc_device *)a)->hash > ((struct tc_device *)b)->hash) return 1;
    else return strcmp(((struct tc_device *)a)->id, ((struct tc_device *)b)->id);
}