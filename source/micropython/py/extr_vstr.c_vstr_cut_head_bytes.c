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
typedef  int /*<<< orphan*/  vstr_t ;

/* Variables and functions */
 int /*<<< orphan*/  vstr_cut_out_bytes (int /*<<< orphan*/ *,int /*<<< orphan*/ ,size_t) ; 

void vstr_cut_head_bytes(vstr_t *vstr, size_t bytes_to_cut) {
    vstr_cut_out_bytes(vstr, 0, bytes_to_cut);
}