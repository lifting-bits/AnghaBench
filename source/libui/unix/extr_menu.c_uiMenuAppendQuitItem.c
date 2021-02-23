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
typedef  int /*<<< orphan*/  uiMenuItem ;
typedef  int /*<<< orphan*/  uiMenu ;

/* Variables and functions */
 scalar_t__ TRUE ; 
 scalar_t__ hasQuit ; 
 int /*<<< orphan*/ * newItem (int /*<<< orphan*/ *,int /*<<< orphan*/ ,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  typeQuit ; 
 int /*<<< orphan*/  typeSeparator ; 
 int /*<<< orphan*/  uiprivUserBug (char*) ; 

uiMenuItem *uiMenuAppendQuitItem(uiMenu *m)
{
	if (hasQuit)
		uiprivUserBug("You cannot have multiple Quit menu items in the same program.");
	hasQuit = TRUE;
	newItem(m, typeSeparator, NULL);
	return newItem(m, typeQuit, NULL);
}