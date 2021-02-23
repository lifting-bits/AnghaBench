#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_3__   TYPE_1__ ;

/* Type definitions */
typedef  TYPE_1__* xsltTransformContextPtr ;
struct TYPE_3__ {int /*<<< orphan*/ * extFunctions; int /*<<< orphan*/ * extElements; } ;

/* Variables and functions */
 int /*<<< orphan*/  xmlHashFree (int /*<<< orphan*/ *,int /*<<< orphan*/ *) ; 

void
xsltFreeCtxtExts(xsltTransformContextPtr ctxt)
{
    if (ctxt->extElements != NULL)
        xmlHashFree(ctxt->extElements, NULL);
    if (ctxt->extFunctions != NULL)
        xmlHashFree(ctxt->extFunctions, NULL);
}