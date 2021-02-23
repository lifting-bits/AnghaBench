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
typedef  int /*<<< orphan*/  Sym ;

/* Variables and functions */
 int /*<<< orphan*/ * map_get (int /*<<< orphan*/ *,void const*) ; 
 int /*<<< orphan*/  resolved_sym_map ; 

Sym *get_resolved_sym(const void *ptr) {
    return map_get(&resolved_sym_map, ptr);
}