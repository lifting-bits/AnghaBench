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
typedef  size_t segmentName_t ;
struct TYPE_5__ {int /*<<< orphan*/  value; TYPE_1__* segment; } ;
struct TYPE_4__ {int /*<<< orphan*/  imageUsed; } ;

/* Variables and functions */
 TYPE_1__* currentSegment ; 
 TYPE_2__* lastSymbol ; 
 scalar_t__ passNumber ; 
 TYPE_1__* segment ; 

void HackToSegment( segmentName_t seg ) {
	if ( currentSegment == &segment[seg] ) {
		return;
	}

	currentSegment = &segment[seg];
	if ( passNumber == 0 ) {
		lastSymbol->segment = currentSegment;
		lastSymbol->value = currentSegment->imageUsed;
	}
}