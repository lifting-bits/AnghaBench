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
struct vo {int dummy; } ;

/* Variables and functions */
 int IMGFMT_BGR24 ; 

__attribute__((used)) static int query_format(struct vo *vo, int format)
{
    return format == IMGFMT_BGR24;
}