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
typedef  int /*<<< orphan*/  RBinFile ;

/* Variables and functions */

__attribute__((used)) static void destroy(RBinFile *bf) {
	//r_bin_fs_free ((struct r_bin_fs_obj_t*)bf->o->bin_obj);
}