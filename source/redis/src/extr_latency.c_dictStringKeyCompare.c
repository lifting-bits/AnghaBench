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

/* Variables and functions */
 int /*<<< orphan*/  UNUSED (void*) ; 
 scalar_t__ strcmp (void const*,void const*) ; 

int dictStringKeyCompare(void *privdata, const void *key1, const void *key2) {
    UNUSED(privdata);
    return strcmp(key1,key2) == 0;
}