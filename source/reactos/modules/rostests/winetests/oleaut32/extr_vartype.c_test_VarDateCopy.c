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

/* Variables and functions */
 int /*<<< orphan*/  COPYTEST (double,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ,char*) ; 
 int /*<<< orphan*/  VT_DATE ; 
 int /*<<< orphan*/  V_DATE (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  V_DATEREF (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  vDst ; 
 int /*<<< orphan*/  vSrc ; 

__attribute__((used)) static void test_VarDateCopy(void)
{
  COPYTEST(77665544.0, VT_DATE, V_DATE(&vSrc), V_DATE(&vDst), V_DATEREF(&vSrc),
           V_DATEREF(&vDst), "%16.16g");
}