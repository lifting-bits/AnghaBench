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

/* Variables and functions */
 int /*<<< orphan*/  Image ; 
 int /*<<< orphan*/  PDF_NAME (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  Subtype ; 
 int /*<<< orphan*/  ctx ; 
 int /*<<< orphan*/ * pdf_dict_get (int /*<<< orphan*/ ,int /*<<< orphan*/ *,int /*<<< orphan*/ ) ; 
 int pdf_name_eq (int /*<<< orphan*/ ,int /*<<< orphan*/ *,int /*<<< orphan*/ ) ; 

__attribute__((used)) static int isimage(pdf_obj *obj)
{
	pdf_obj *type = pdf_dict_get(ctx, obj, PDF_NAME(Subtype));
	return pdf_name_eq(ctx, type, PDF_NAME(Image));
}