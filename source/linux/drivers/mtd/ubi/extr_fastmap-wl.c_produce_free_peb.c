#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_2__   TYPE_1__ ;

/* Type definitions */
struct TYPE_2__ {int /*<<< orphan*/  rb_node; } ;
struct ubi_device {scalar_t__ works_count; TYPE_1__ free; } ;

/* Variables and functions */
 int /*<<< orphan*/  dbg_wl (char*) ; 
 int do_work (struct ubi_device*) ; 

__attribute__((used)) static int produce_free_peb(struct ubi_device *ubi)
{
	int err;

	while (!ubi->free.rb_node && ubi->works_count) {
		dbg_wl("do one work synchronously");
		err = do_work(ubi);

		if (err)
			return err;
	}

	return 0;
}