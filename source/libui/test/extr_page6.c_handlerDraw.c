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
typedef  int /*<<< orphan*/  uiAreaHandler ;
typedef  int /*<<< orphan*/  uiAreaDrawParams ;
typedef  int /*<<< orphan*/  uiArea ;

/* Variables and functions */
 int /*<<< orphan*/  runDrawTest (int /*<<< orphan*/ ,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  uiComboboxSelected (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  which ; 

__attribute__((used)) static void handlerDraw(uiAreaHandler *a, uiArea *area, uiAreaDrawParams *p)
{
	runDrawTest(uiComboboxSelected(which), p);
}