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
struct vt_window {int dummy; } ;

/* Variables and functions */
 int /*<<< orphan*/  signal_vt_acq (struct vt_window*) ; 

__attribute__((used)) static int
vt_window_postswitch(struct vt_window *vw)
{

	signal_vt_acq(vw);
	return (0);
}