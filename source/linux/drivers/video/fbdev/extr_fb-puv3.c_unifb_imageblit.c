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
struct fb_info {int dummy; } ;
struct fb_image {int dummy; } ;

/* Variables and functions */
 int /*<<< orphan*/  sys_imageblit (struct fb_info*,struct fb_image const*) ; 

__attribute__((used)) static void unifb_imageblit(struct fb_info *info, const struct fb_image *image)
{
	sys_imageblit(info, image);
}