#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_5__   TYPE_2__ ;
typedef  struct TYPE_4__   TYPE_1__ ;

/* Type definitions */
typedef  int uint8_t ;
struct TYPE_4__ {int /*<<< orphan*/  pressed; } ;
struct TYPE_5__ {TYPE_1__ event; } ;
typedef  TYPE_2__ keyrecord_t ;

/* Variables and functions */
 int /*<<< orphan*/  rgblight_mode (int) ; 
 int /*<<< orphan*/  rgblight_sethsv (int,int,int) ; 

void action_function(keyrecord_t *record, uint8_t id, uint8_t opt) {
  switch (id) {
    case 0:
      if (record->event.pressed) {
        rgblight_mode(1);
        rgblight_sethsv(206, 255, 255);
      }
  }
}