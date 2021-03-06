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
struct omap_mbox {TYPE_1__* ops; } ;
typedef  int /*<<< orphan*/  mbox_msg_t ;
struct TYPE_2__ {int /*<<< orphan*/  (* fifo_write ) (struct omap_mbox*,int /*<<< orphan*/ ) ;} ;

/* Variables and functions */
 int /*<<< orphan*/  stub1 (struct omap_mbox*,int /*<<< orphan*/ ) ; 

__attribute__((used)) static inline void mbox_fifo_write(struct omap_mbox *mbox, mbox_msg_t msg)
{
	mbox->ops->fifo_write(mbox, msg);
}