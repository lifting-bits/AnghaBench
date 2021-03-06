#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_8__   TYPE_3__ ;
typedef  struct TYPE_7__   TYPE_2__ ;
typedef  struct TYPE_6__   TYPE_1__ ;

/* Type definitions */
struct TYPE_8__ {scalar_t__ windingNumber; } ;
struct TYPE_7__ {scalar_t__ windingNumber; int /*<<< orphan*/  inside; TYPE_1__* eUp; } ;
struct TYPE_6__ {scalar_t__ winding; } ;
typedef  int /*<<< orphan*/  GLUtesselator ;
typedef  TYPE_2__ ActiveRegion ;

/* Variables and functions */
 int /*<<< orphan*/  IsWindingInside (int /*<<< orphan*/ *,scalar_t__) ; 
 TYPE_3__* RegionAbove (TYPE_2__*) ; 

__attribute__((used)) static void ComputeWinding( GLUtesselator *tess, ActiveRegion *reg )
{
  reg->windingNumber = RegionAbove(reg)->windingNumber + reg->eUp->winding;
  reg->inside = IsWindingInside( tess, reg->windingNumber );
}