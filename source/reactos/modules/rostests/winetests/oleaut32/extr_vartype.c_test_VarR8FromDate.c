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
 int /*<<< orphan*/  CONVERT (int /*<<< orphan*/ ,double) ; 
 int /*<<< orphan*/  CONVVARS (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  DATE ; 
 int /*<<< orphan*/  EXPECT (double) ; 
 int /*<<< orphan*/  VarR8FromDate ; 

__attribute__((used)) static void test_VarR8FromDate(void)
{
  CONVVARS(DATE);

  CONVERT(VarR8FromDate, -1.0); EXPECT(-1.0);
  CONVERT(VarR8FromDate, -0.0); EXPECT(0.0);
  CONVERT(VarR8FromDate, 1.0);  EXPECT(1.0);
}