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
 int /*<<< orphan*/  CONVERT (int /*<<< orphan*/ ,int) ; 
 int /*<<< orphan*/  CONVERTRANGE (int /*<<< orphan*/ ,int /*<<< orphan*/ ,int) ; 
 int /*<<< orphan*/  CONVVARS (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  EXPECT (int) ; 
 int /*<<< orphan*/  VARIANT_BOOL ; 
 int /*<<< orphan*/  VarUI2FromBool ; 

__attribute__((used)) static void test_VarUI2FromBool(void)
{
  CONVVARS(VARIANT_BOOL);
  int i;

  CONVERT(VarUI2FromBool, -1); EXPECT(65535); /* Wraps! */
  CONVERTRANGE(VarUI2FromBool, 0, 32768);
}