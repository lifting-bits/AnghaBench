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
typedef  TYPE_1__* xsltStylesheetPtr ;
struct TYPE_4__ {int /*<<< orphan*/ * extInfos; } ;

/* Variables and functions */
 int /*<<< orphan*/  xmlHashFree (int /*<<< orphan*/ *,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  xmlHashScan (int /*<<< orphan*/ *,int /*<<< orphan*/ ,TYPE_1__*) ; 
 int /*<<< orphan*/  xsltFreeExtDataEntry ; 
 int /*<<< orphan*/  xsltShutdownExt ; 

void
xsltShutdownExts(xsltStylesheetPtr style)
{
    if (style == NULL)
        return;
    if (style->extInfos == NULL)
        return;
    xmlHashScan(style->extInfos, xsltShutdownExt, style);
    xmlHashFree(style->extInfos, xsltFreeExtDataEntry);
    style->extInfos = NULL;
}