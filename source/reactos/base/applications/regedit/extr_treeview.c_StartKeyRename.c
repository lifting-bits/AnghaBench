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
typedef  int /*<<< orphan*/  HWND ;
typedef  int /*<<< orphan*/  HTREEITEM ;

/* Variables and functions */
 int /*<<< orphan*/  TreeView_EditLabel (int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  TreeView_GetSelection (int /*<<< orphan*/ ) ; 

HWND StartKeyRename(HWND hwndTV)
{
    HTREEITEM hItem;

    if(!(hItem = TreeView_GetSelection(hwndTV))) return 0;
    return TreeView_EditLabel(hwndTV, hItem);
}