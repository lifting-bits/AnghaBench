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
typedef  int /*<<< orphan*/  int32_t ;
typedef  int /*<<< orphan*/  fe ;

/* Variables and functions */
 int /*<<< orphan*/  memmove (int /*<<< orphan*/ ,int /*<<< orphan*/  const,int) ; 

__attribute__((used)) static void fe_copy(fe h, const fe f)
{
    memmove(h, f, sizeof(int32_t) * 10);
}