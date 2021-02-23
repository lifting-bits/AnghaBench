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
typedef  int /*<<< orphan*/  png_uint_32 ;
typedef  int /*<<< orphan*/  png_structrp ;
typedef  int /*<<< orphan*/  png_size_t ;
typedef  scalar_t__ png_byte ;

/* Variables and functions */
 int PNG_RESOLUTION_LAST ; 
 int /*<<< orphan*/  png_debug (int,char*) ; 
 int /*<<< orphan*/  png_pHYs ; 
 int /*<<< orphan*/  png_save_uint_32 (scalar_t__*,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  png_warning (int /*<<< orphan*/ ,char*) ; 
 int /*<<< orphan*/  png_write_complete_chunk (int /*<<< orphan*/ ,int /*<<< orphan*/ ,scalar_t__*,int /*<<< orphan*/ ) ; 

void /* PRIVATE */
png_write_pHYs(png_structrp png_ptr, png_uint_32 x_pixels_per_unit,
    png_uint_32 y_pixels_per_unit,
    int unit_type)
{
   png_byte buf[9];

   png_debug(1, "in png_write_pHYs");

   if (unit_type >= PNG_RESOLUTION_LAST)
      png_warning(png_ptr, "Unrecognized unit type for pHYs chunk");

   png_save_uint_32(buf, x_pixels_per_unit);
   png_save_uint_32(buf + 4, y_pixels_per_unit);
   buf[8] = (png_byte)unit_type;

   png_write_complete_chunk(png_ptr, png_pHYs, buf, (png_size_t)9);
}