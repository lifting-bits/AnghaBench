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
struct TYPE_3__ {int /*<<< orphan*/  storable; } ;
typedef  TYPE_1__ fz_html ;
typedef  int /*<<< orphan*/  fz_context ;

/* Variables and functions */
 int /*<<< orphan*/  fz_defer_reap_end (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  fz_defer_reap_start (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  fz_drop_storable (int /*<<< orphan*/ *,int /*<<< orphan*/ *) ; 

void fz_drop_html(fz_context *ctx, fz_html *html)
{
	fz_defer_reap_start(ctx);
	fz_drop_storable(ctx, &html->storable);
	fz_defer_reap_end(ctx);
}