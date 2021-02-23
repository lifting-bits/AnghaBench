#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_5__   TYPE_1__ ;

/* Type definitions */
struct TYPE_5__ {int /*<<< orphan*/  storable; } ;
typedef  TYPE_1__ pdf_font_desc ;
typedef  int /*<<< orphan*/  fz_context ;

/* Variables and functions */
 TYPE_1__* fz_keep_storable (int /*<<< orphan*/ *,int /*<<< orphan*/ *) ; 

pdf_font_desc *
pdf_keep_font(fz_context *ctx, pdf_font_desc *fontdesc)
{
	return fz_keep_storable(ctx, &fontdesc->storable);
}