#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_5__   TYPE_2__ ;
typedef  struct TYPE_4__   TYPE_1__ ;

/* Type definitions */
struct r_bin_mz_obj_t {int /*<<< orphan*/ * kv; } ;
struct TYPE_5__ {TYPE_1__* o; } ;
struct TYPE_4__ {scalar_t__ bin_obj; } ;
typedef  int /*<<< orphan*/  Sdb ;
typedef  TYPE_2__ RBinFile ;

/* Variables and functions */

__attribute__((used)) static Sdb *get_sdb(RBinFile *bf) {
	const struct r_bin_mz_obj_t *bin;
	if (bf && bf->o && bf->o->bin_obj) {
		bin = (struct r_bin_mz_obj_t *)bf->o->bin_obj;
		if (bin && bin->kv) {
			return bin->kv;
		}
	}
	return NULL;
}