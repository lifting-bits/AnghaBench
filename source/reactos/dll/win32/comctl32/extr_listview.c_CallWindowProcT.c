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
typedef  int /*<<< orphan*/  WPARAM ;
typedef  int /*<<< orphan*/  WNDPROC ;
typedef  int /*<<< orphan*/  UINT ;
typedef  int /*<<< orphan*/  LRESULT ;
typedef  int /*<<< orphan*/  LPARAM ;
typedef  int /*<<< orphan*/  HWND ;
typedef  scalar_t__ BOOL ;

/* Variables and functions */
 int /*<<< orphan*/  CallWindowProcA (int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  CallWindowProcW (int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 

__attribute__((used)) static inline LRESULT CallWindowProcT(WNDPROC proc, HWND hwnd, UINT uMsg,
		                      WPARAM wParam, LPARAM lParam, BOOL isW)
{
    if (isW) return CallWindowProcW(proc, hwnd, uMsg, wParam, lParam);
    else return CallWindowProcA(proc, hwnd, uMsg, wParam, lParam);
}