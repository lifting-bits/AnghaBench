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
typedef  int /*<<< orphan*/  pdf_obj ;
typedef  int /*<<< orphan*/  fz_context ;

/* Variables and functions */
 int /*<<< orphan*/  Group ; 
 int /*<<< orphan*/  K ; 
 int /*<<< orphan*/  PDF_NAME (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/ * pdf_dict_get (int /*<<< orphan*/ *,int /*<<< orphan*/ *,int /*<<< orphan*/ ) ; 
 int pdf_dict_get_bool (int /*<<< orphan*/ *,int /*<<< orphan*/ *,int /*<<< orphan*/ ) ; 

int pdf_xobject_knockout(fz_context *ctx, pdf_obj *xobj)
{
	pdf_obj *group = pdf_dict_get(ctx, xobj, PDF_NAME(Group));
	if (group)
		return pdf_dict_get_bool(ctx, group, PDF_NAME(K));
	return 0;
}