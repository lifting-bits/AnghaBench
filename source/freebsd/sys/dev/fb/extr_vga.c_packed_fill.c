#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_6__   TYPE_2__ ;
typedef  struct TYPE_5__   TYPE_1__ ;

/* Type definitions */
struct TYPE_5__ {int vi_height; } ;
struct TYPE_6__ {int va_line_width; int /*<<< orphan*/  va_window; int /*<<< orphan*/  va_window_size; TYPE_1__ va_info; } ;
typedef  TYPE_2__ video_adapter_t ;

/* Variables and functions */
 int /*<<< orphan*/  fill_io (int,int /*<<< orphan*/ ,int) ; 
 int imin (int,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  vidd_set_win_org (TYPE_2__*,int) ; 

__attribute__((used)) static void
packed_fill(video_adapter_t *adp, int val)
{
    int length;
    int at;			/* position in the frame buffer */
    int l;

    at = 0;
    length = adp->va_line_width*adp->va_info.vi_height;
    while (length > 0) {
	l = imin(length, adp->va_window_size);
	vidd_set_win_org(adp, at);
	fill_io(val, adp->va_window, l);
	length -= l;
	at += l;
    }
}