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
typedef  int /*<<< orphan*/  png_uint_16 ;

/* Variables and functions */
 int* sRGB_to_d ; 
 int /*<<< orphan*/  u16d (int) ; 

__attribute__((used)) static png_uint_16
ilineara(int fixed_srgb, int alpha)
{
   return u16d((257 * alpha) * sRGB_to_d[fixed_srgb]);
}