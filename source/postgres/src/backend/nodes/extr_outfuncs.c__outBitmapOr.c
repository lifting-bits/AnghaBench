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
typedef  int /*<<< orphan*/  StringInfo ;
typedef  int /*<<< orphan*/  Plan ;
typedef  int /*<<< orphan*/  BitmapOr ;

/* Variables and functions */
 int /*<<< orphan*/  WRITE_BOOL_FIELD (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  WRITE_NODE_FIELD (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  WRITE_NODE_TYPE (char*) ; 
 int /*<<< orphan*/  _outPlanInfo (int /*<<< orphan*/ ,int /*<<< orphan*/  const*) ; 
 int /*<<< orphan*/  bitmapplans ; 
 int /*<<< orphan*/  isshared ; 

__attribute__((used)) static void
_outBitmapOr(StringInfo str, const BitmapOr *node)
{
	WRITE_NODE_TYPE("BITMAPOR");

	_outPlanInfo(str, (const Plan *) node);

	WRITE_BOOL_FIELD(isshared);
	WRITE_NODE_FIELD(bitmapplans);
}