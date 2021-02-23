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
typedef  int /*<<< orphan*/  AVFilterContext ;

/* Variables and functions */
 int /*<<< orphan*/  ff_make_format_list (int /*<<< orphan*/ ) ; 
 int ff_set_common_formats (int /*<<< orphan*/ *,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  pix_fmts ; 

__attribute__((used)) static int query_formats(AVFilterContext *ctx)
{
    return ff_set_common_formats(ctx, ff_make_format_list(pix_fmts));
}