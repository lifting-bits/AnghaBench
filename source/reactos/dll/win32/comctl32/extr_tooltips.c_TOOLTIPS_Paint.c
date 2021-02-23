#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_4__   TYPE_1__ ;

/* Type definitions */
struct TYPE_4__ {int /*<<< orphan*/  hwndSelf; } ;
typedef  TYPE_1__ TOOLTIPS_INFO ;
typedef  int /*<<< orphan*/  PAINTSTRUCT ;
typedef  int /*<<< orphan*/  LRESULT ;
typedef  int /*<<< orphan*/ * HDC ;

/* Variables and functions */
 int /*<<< orphan*/ * BeginPaint (int /*<<< orphan*/ ,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  EndPaint (int /*<<< orphan*/ ,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  TOOLTIPS_Refresh (TYPE_1__ const*,int /*<<< orphan*/ *) ; 

__attribute__((used)) static LRESULT
TOOLTIPS_Paint (const TOOLTIPS_INFO *infoPtr, HDC hDC)
{
    HDC hdc;
    PAINTSTRUCT ps;

    hdc = (hDC == NULL) ? BeginPaint (infoPtr->hwndSelf, &ps) : hDC;
    TOOLTIPS_Refresh (infoPtr, hdc);
    if (!hDC)
	EndPaint (infoPtr->hwndSelf, &ps);
    return 0;
}