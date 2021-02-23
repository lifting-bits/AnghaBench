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
typedef  int /*<<< orphan*/  zval ;
typedef  int /*<<< orphan*/  xmlDocPtr ;

/* Variables and functions */
 int /*<<< orphan*/  Z_PTR_P (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  xmlFreeDoc (int /*<<< orphan*/ ) ; 

__attribute__((used)) static void delete_document(zval *zv)
{
	xmlDocPtr doc = Z_PTR_P(zv);
	xmlFreeDoc(doc);
}