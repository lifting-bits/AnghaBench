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
struct vt_buf {int dummy; } ;

/* Variables and functions */
 int /*<<< orphan*/  VTBUF_UNLOCK (struct vt_buf*) ; 

void
vtbuf_unlock(struct vt_buf *vb)
{

	VTBUF_UNLOCK(vb);
}