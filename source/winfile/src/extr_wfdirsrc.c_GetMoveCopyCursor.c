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
typedef  int /*<<< orphan*/  LPTSTR ;
typedef  int /*<<< orphan*/  HCURSOR ;

/* Variables and functions */
 int /*<<< orphan*/  LoadCursor (int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 scalar_t__ MAKEINTRESOURCE (int) ; 
 scalar_t__ fShowSourceBitmaps ; 
 int /*<<< orphan*/  hAppInstance ; 
 int iCurDrag ; 

HCURSOR
GetMoveCopyCursor()
{
   if (fShowSourceBitmaps) {
      // copy
      return LoadCursor(hAppInstance, (LPTSTR) MAKEINTRESOURCE(iCurDrag | 1));
   } else {
      // move
      return LoadCursor(hAppInstance, (LPTSTR) MAKEINTRESOURCE(iCurDrag & ~1));
   }
}