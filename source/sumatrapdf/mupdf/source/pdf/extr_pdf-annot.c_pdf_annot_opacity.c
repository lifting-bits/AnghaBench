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
typedef  int /*<<< orphan*/  pdf_obj ;
struct TYPE_3__ {int /*<<< orphan*/  obj; } ;
typedef  TYPE_1__ pdf_annot ;
typedef  int /*<<< orphan*/  fz_context ;

/* Variables and functions */
 int /*<<< orphan*/  CA ; 
 int /*<<< orphan*/  PDF_NAME (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/ * pdf_dict_get (int /*<<< orphan*/ *,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 scalar_t__ pdf_is_number (int /*<<< orphan*/ *,int /*<<< orphan*/ *) ; 
 float pdf_to_real (int /*<<< orphan*/ *,int /*<<< orphan*/ *) ; 

float pdf_annot_opacity(fz_context *ctx, pdf_annot *annot)
{
	pdf_obj *ca = pdf_dict_get(ctx, annot->obj, PDF_NAME(CA));
	if (pdf_is_number(ctx, ca))
		return pdf_to_real(ctx, ca);
	return 1;
}