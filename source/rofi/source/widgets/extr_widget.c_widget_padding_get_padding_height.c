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
typedef  int /*<<< orphan*/  widget ;

/* Variables and functions */
 scalar_t__ widget_padding_get_bottom (int /*<<< orphan*/  const*) ; 
 scalar_t__ widget_padding_get_top (int /*<<< orphan*/  const*) ; 

int widget_padding_get_padding_height ( const widget *wid )
{
    int height = 0;
    height += widget_padding_get_top ( wid );
    height += widget_padding_get_bottom ( wid );
    return height;
}