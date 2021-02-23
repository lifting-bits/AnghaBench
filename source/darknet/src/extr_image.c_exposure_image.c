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
typedef  int /*<<< orphan*/  image ;

/* Variables and functions */
 int /*<<< orphan*/  constrain_image (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  hsv_to_rgb (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  rgb_to_hsv (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  scale_image_channel (int /*<<< orphan*/ ,int,float) ; 

void exposure_image(image im, float sat)
{
    rgb_to_hsv(im);
    scale_image_channel(im, 2, sat);
    hsv_to_rgb(im);
    constrain_image(im);
}