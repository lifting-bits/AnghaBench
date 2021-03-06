#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_2__   TYPE_1__ ;

/* Type definitions */
typedef  int /*<<< orphan*/  u32 ;
struct TYPE_2__ {int is_muted; } ;

/* Variables and functions */
 int NUM_DEBUG_INSTRUMENTS ; 
 TYPE_1__* debug_instruments ; 
 int /*<<< orphan*/  scsp_debug_search_instruments (int /*<<< orphan*/ ,int*,int*) ; 

void scsp_debug_instrument_set_mute(u32 sa, int mute)
{
   int found = 0, offset = 0;
   scsp_debug_search_instruments(sa, &found, &offset);

   if (offset >= NUM_DEBUG_INSTRUMENTS)
      return;

   if (found)
      debug_instruments[offset].is_muted = mute;
}