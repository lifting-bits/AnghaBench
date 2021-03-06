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
struct gntdev_gmap {int file_index; } ;

/* Variables and functions */

__attribute__((used)) static int
gmap_cmp(struct gntdev_gmap *g1, struct gntdev_gmap *g2)
{
	return (g1->file_index - g2->file_index);
}