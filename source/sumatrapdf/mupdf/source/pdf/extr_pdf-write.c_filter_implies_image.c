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
 int is_image_filter (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/ * pdf_array_get (int /*<<< orphan*/ *,int /*<<< orphan*/ *,int) ; 
 int pdf_array_len (int /*<<< orphan*/ *,int /*<<< orphan*/ *) ; 
 scalar_t__ pdf_is_array (int /*<<< orphan*/ *,int /*<<< orphan*/ *) ; 
 scalar_t__ pdf_is_name (int /*<<< orphan*/ *,int /*<<< orphan*/ *) ; 

__attribute__((used)) static int filter_implies_image(fz_context *ctx, pdf_obj *o)
{
	if (pdf_is_name(ctx, o))
		return is_image_filter(o);
	if (pdf_is_array(ctx, o))
	{
		int i, len;
		len = pdf_array_len(ctx, o);
		for (i = 0; i < len; i++)
			if (is_image_filter(pdf_array_get(ctx, o, i)))
				return 1;
	}
	return 0;
}