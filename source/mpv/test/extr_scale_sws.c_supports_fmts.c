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
struct mp_sws_context {int dummy; } ;

/* Variables and functions */
 int mp_sws_supports_formats (struct mp_sws_context*,int,int) ; 

__attribute__((used)) static bool supports_fmts(void *pctx, int imgfmt_dst, int imgfmt_src)
{
    struct mp_sws_context *ctx = pctx;
    return mp_sws_supports_formats(ctx, imgfmt_dst, imgfmt_src);
}