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
typedef  int /*<<< orphan*/  uint32_t ;

/* Variables and functions */
 int /*<<< orphan*/  D1 ; 
 int biton32 (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  writePinHigh (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  writePinLow (int /*<<< orphan*/ ) ; 

uint32_t layer_state_set_user(uint32_t state) {
    switch (biton32(state)) {
      case 1:
        writePinHigh(D1);
        break;
      default: //  for any other layers, or the default layer
        writePinLow(D1);
        break;
      }
    return state;
}