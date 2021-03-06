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
typedef  int /*<<< orphan*/  HeapTuple ;

/* Variables and functions */
 int /*<<< orphan*/  heap_freetuple (int /*<<< orphan*/ ) ; 

void
SPI_freetuple(HeapTuple tuple)
{
	/* No longer need to worry which context tuple was in... */
	heap_freetuple(tuple);
}