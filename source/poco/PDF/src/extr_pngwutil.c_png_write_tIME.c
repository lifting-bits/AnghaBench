#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_3__   TYPE_1__ ;

/* Type definitions */
typedef  TYPE_1__* png_timep ;
typedef  int /*<<< orphan*/  png_structp ;
typedef  int /*<<< orphan*/  png_size_t ;
typedef  int png_byte ;
struct TYPE_3__ {int month; int day; int hour; int second; int minute; int /*<<< orphan*/  year; } ;

/* Variables and functions */
 int /*<<< orphan*/  PNG_tIME ; 
 int /*<<< orphan*/  png_debug (int,char*) ; 
 int /*<<< orphan*/  png_save_uint_16 (int*,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  png_tIME ; 
 int /*<<< orphan*/  png_warning (int /*<<< orphan*/ ,char*) ; 
 int /*<<< orphan*/  png_write_chunk (int /*<<< orphan*/ ,int /*<<< orphan*/ ,int*,int /*<<< orphan*/ ) ; 

void /* PRIVATE */
png_write_tIME(png_structp png_ptr, png_timep mod_time)
{
#ifdef PNG_USE_LOCAL_ARRAYS
   PNG_tIME;
#endif
   png_byte buf[7];

   png_debug(1, "in png_write_tIME\n");
   if (mod_time->month  > 12 || mod_time->month  < 1 ||
       mod_time->day    > 31 || mod_time->day    < 1 ||
       mod_time->hour   > 23 || mod_time->second > 60)
   {
      png_warning(png_ptr, "Invalid time specified for tIME chunk");
      return;
   }

   png_save_uint_16(buf, mod_time->year);
   buf[2] = mod_time->month;
   buf[3] = mod_time->day;
   buf[4] = mod_time->hour;
   buf[5] = mod_time->minute;
   buf[6] = mod_time->second;

   png_write_chunk(png_ptr, png_tIME, buf, (png_size_t)7);
}