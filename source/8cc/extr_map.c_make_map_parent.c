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
typedef  int /*<<< orphan*/  Map ;

/* Variables and functions */
 int /*<<< orphan*/  INIT_SIZE ; 
 int /*<<< orphan*/ * do_make_map (int /*<<< orphan*/ *,int /*<<< orphan*/ ) ; 

Map *make_map_parent(Map *parent) {
    return do_make_map(parent, INIT_SIZE);
}