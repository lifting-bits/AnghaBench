#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_3__   TYPE_1__ ;

/* Type definitions */
typedef  int /*<<< orphan*/  xuio_t ;
struct TYPE_3__ {int cnt; int /*<<< orphan*/ ** bufs; } ;
typedef  TYPE_1__ dmu_xuio_t ;

/* Variables and functions */
 int /*<<< orphan*/  ASSERT (int) ; 
 TYPE_1__* XUIO_XUZC_PRIV (int /*<<< orphan*/ *) ; 

void
dmu_xuio_clear(xuio_t *xuio, int i)
{
	dmu_xuio_t *priv = XUIO_XUZC_PRIV(xuio);

	ASSERT(i < priv->cnt);
	priv->bufs[i] = NULL;
}