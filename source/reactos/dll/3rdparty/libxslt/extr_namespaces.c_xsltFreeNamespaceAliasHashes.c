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
typedef  TYPE_1__* xsltStylesheetPtr ;
typedef  int /*<<< orphan*/  xmlHashTablePtr ;
struct TYPE_3__ {int /*<<< orphan*/ * nsAliases; } ;

/* Variables and functions */
 int /*<<< orphan*/  xmlHashFree (int /*<<< orphan*/ ,int /*<<< orphan*/ *) ; 

void
xsltFreeNamespaceAliasHashes(xsltStylesheetPtr style) {
    if (style->nsAliases != NULL)
	xmlHashFree((xmlHashTablePtr) style->nsAliases, NULL);
    style->nsAliases = NULL;
}