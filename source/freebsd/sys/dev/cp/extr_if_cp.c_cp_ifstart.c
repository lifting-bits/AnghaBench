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
struct ifnet {TYPE_2__* if_softc; } ;
struct TYPE_5__ {TYPE_1__* board; } ;
typedef  TYPE_2__ drv_t ;
typedef  int /*<<< orphan*/  bdrv_t ;
struct TYPE_4__ {int /*<<< orphan*/ * sys; } ;

/* Variables and functions */
 int /*<<< orphan*/  CP_LOCK (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  CP_UNLOCK (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  cp_start (TYPE_2__*) ; 

__attribute__((used)) static void cp_ifstart (struct ifnet *ifp)
{
	drv_t *d = ifp->if_softc;
	bdrv_t *bd = d->board->sys;

	CP_LOCK (bd);
	cp_start (d);
	CP_UNLOCK (bd);
}