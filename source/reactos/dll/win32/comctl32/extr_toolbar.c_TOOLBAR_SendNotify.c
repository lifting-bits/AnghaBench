#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_6__   TYPE_2__ ;
typedef  struct TYPE_5__   TYPE_1__ ;

/* Type definitions */
typedef  int /*<<< orphan*/  UINT ;
struct TYPE_6__ {int /*<<< orphan*/  idFrom; int /*<<< orphan*/  code; int /*<<< orphan*/  hwndFrom; } ;
struct TYPE_5__ {int /*<<< orphan*/  hwndNotify; scalar_t__ bUnicode; int /*<<< orphan*/  hwndSelf; } ;
typedef  TYPE_1__ TOOLBAR_INFO ;
typedef  TYPE_2__ NMHDR ;
typedef  int /*<<< orphan*/  LPARAM ;
typedef  int /*<<< orphan*/  INT ;

/* Variables and functions */
 int /*<<< orphan*/  GetDlgCtrlID (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  IsWindow (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  SendMessageW (int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  TRACE (char*,int /*<<< orphan*/ ,int /*<<< orphan*/ ,char*) ; 
 int /*<<< orphan*/  WM_NOTIFY ; 

__attribute__((used)) static INT
TOOLBAR_SendNotify (NMHDR *nmhdr, const TOOLBAR_INFO *infoPtr, UINT code)
{
	if(!IsWindow(infoPtr->hwndSelf))
	    return 0;   /* we have just been destroyed */

    nmhdr->idFrom = GetDlgCtrlID (infoPtr->hwndSelf);
    nmhdr->hwndFrom = infoPtr->hwndSelf;
    nmhdr->code = code;

    TRACE("to window %p, code=%08x, %s\n", infoPtr->hwndNotify, code,
	  (infoPtr->bUnicode) ? "via Unicode" : "via ANSI");

    return SendMessageW(infoPtr->hwndNotify, WM_NOTIFY, nmhdr->idFrom, (LPARAM)nmhdr);
}