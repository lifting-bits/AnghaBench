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
struct COverflowData {int dummy; } ;

/* Variables and functions */
 int /*<<< orphan*/  ASSERT (struct COverflowData*) ; 
 int /*<<< orphan*/  HandleOverflow (int,struct COverflowData*,unsigned long,unsigned long,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  PLUS_STRING ; 

void
__ubsan_handle_add_overflow_abort(struct COverflowData *pData, unsigned long ulLHS, unsigned long ulRHS)
{

	ASSERT(pData);

	HandleOverflow(true, pData, ulLHS, ulRHS, PLUS_STRING);
}