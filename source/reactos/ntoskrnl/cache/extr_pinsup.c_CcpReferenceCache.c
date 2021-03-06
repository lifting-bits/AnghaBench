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
typedef  int /*<<< orphan*/  VOID ;
typedef  size_t ULONG ;
struct TYPE_3__ {int /*<<< orphan*/  RefCount; int /*<<< orphan*/  SectionObject; } ;
typedef  TYPE_1__* PNOCC_BCB ;

/* Variables and functions */
 int /*<<< orphan*/  ASSERT (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  CcCacheBitmap ; 
 TYPE_1__* CcCacheSections ; 
 int /*<<< orphan*/  RtlSetBit (int /*<<< orphan*/ ,size_t) ; 

VOID
CcpReferenceCache(ULONG Start)
{
    PNOCC_BCB Bcb;
    Bcb = &CcCacheSections[Start];
    ASSERT(Bcb->SectionObject);
    Bcb->RefCount++;
    RtlSetBit(CcCacheBitmap, Start);

}