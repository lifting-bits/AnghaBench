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
typedef  scalar_t__ HDC ;

/* Variables and functions */
 scalar_t__ GdiConvertDC (scalar_t__) ; 
 int /*<<< orphan*/  ok (int,char*) ; 

void Test_GdiConvertDC()
{
    ok(GdiConvertDC((HDC)-1) == (HDC)-1, "\n");
    ok(GdiConvertDC((HDC)0) == (HDC)0, "\n");
    ok(GdiConvertDC((HDC)1) == (HDC)1, "\n");
    ok(GdiConvertDC((HDC)2) == (HDC)2, "\n");
}