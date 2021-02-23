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
typedef  int /*<<< orphan*/  uint64_t ;
typedef  int /*<<< orphan*/  Map ;

/* Variables and functions */
 int /*<<< orphan*/  map_get_uint64_from_uint64 (int /*<<< orphan*/ *,int /*<<< orphan*/ ) ; 

uint64_t map_get_uint64(Map *map, void *key) {
    return map_get_uint64_from_uint64(map, (uint64_t)(uintptr_t)key);
}