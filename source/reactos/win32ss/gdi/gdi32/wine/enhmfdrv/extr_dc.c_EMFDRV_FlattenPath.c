#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_4__   TYPE_2__ ;
typedef  struct TYPE_3__   TYPE_1__ ;

/* Type definitions */
typedef  int /*<<< orphan*/  emr ;
struct TYPE_4__ {int nSize; int /*<<< orphan*/  iType; } ;
struct TYPE_3__ {TYPE_2__ emr; } ;
typedef  int /*<<< orphan*/  PHYSDEV ;
typedef  TYPE_1__ EMRFLATTENPATH ;
typedef  int /*<<< orphan*/  BOOL ;

/* Variables and functions */
 int /*<<< orphan*/  EMFDRV_WriteRecord (int /*<<< orphan*/ ,TYPE_2__*) ; 
 int /*<<< orphan*/  EMR_FLATTENPATH ; 

BOOL EMFDRV_FlattenPath( PHYSDEV dev )
{
    EMRFLATTENPATH emr;

    emr.emr.iType = EMR_FLATTENPATH;
    emr.emr.nSize = sizeof(emr);

    return EMFDRV_WriteRecord( dev, &emr.emr );
}