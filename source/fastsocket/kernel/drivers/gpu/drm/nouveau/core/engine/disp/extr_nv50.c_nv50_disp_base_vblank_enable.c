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
struct nouveau_event {int /*<<< orphan*/  priv; } ;

/* Variables and functions */
 int /*<<< orphan*/  nv_mask (int /*<<< orphan*/ ,int,int,int) ; 

__attribute__((used)) static void
nv50_disp_base_vblank_enable(struct nouveau_event *event, int head)
{
	nv_mask(event->priv, 0x61002c, (4 << head), (4 << head));
}