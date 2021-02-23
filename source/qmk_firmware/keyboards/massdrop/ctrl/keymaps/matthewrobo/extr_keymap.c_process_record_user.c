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
typedef  int /*<<< orphan*/  uint32_t ;
typedef  int uint16_t ;
struct TYPE_4__ {int /*<<< orphan*/  pressed; } ;
struct TYPE_5__ {TYPE_1__ event; } ;
typedef  TYPE_2__ keyrecord_t ;

/* Variables and functions */
#define  DBG_KBD 148 
#define  DBG_MOU 147 
#define  DBG_MTRX 146 
#define  DBG_TOG 145 
#define  LED_FLAG_ALL 144 
#define  LED_FLAG_KEYLIGHT 143 
 int const LED_FLAG_NONE ; 
#define  LED_FLAG_UNDERGLOW 142 
#define  MAS_BLU 141 
#define  MAS_CRM 140 
#define  MAS_CYN 139 
#define  MAS_GRN 138 
#define  MAS_KEY 137 
#define  MAS_MGT 136 
#define  MAS_PRP 135 
#define  MAS_RED 134 
#define  MAS_TOG 133 
#define  MAS_WHT 132 
#define  MAS_YEL 131 
#define  MD_BOOT 130 
 int /*<<< orphan*/  MODS_CTRL ; 
 int /*<<< orphan*/  MODS_SHIFT ; 
 int /*<<< orphan*/  TOGGLE_FLAG_AND_PRINT (int /*<<< orphan*/ ,char*) ; 
#define  U_T_AGCR 129 
#define  U_T_AUTO 128 
 int /*<<< orphan*/  debug_enable ; 
 int /*<<< orphan*/  debug_keyboard ; 
 int /*<<< orphan*/  debug_matrix ; 
 int /*<<< orphan*/  debug_mouse ; 
 int /*<<< orphan*/  reset_keyboard () ; 
 int /*<<< orphan*/  rgb_matrix_disable_noeeprom () ; 
 int /*<<< orphan*/  rgb_matrix_get_flags () ; 
 int /*<<< orphan*/  rgb_matrix_set_color_all (int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  rgb_matrix_set_flags (int const) ; 
 int /*<<< orphan*/  rgb_matrix_sethsv (int,int,int) ; 
 int timer_elapsed32 (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  timer_read32 () ; 
 int /*<<< orphan*/  usb_extra_manual ; 
 int /*<<< orphan*/  usb_gcr_auto ; 

bool process_record_user(uint16_t keycode, keyrecord_t* record)
{
	static uint32_t key_timer;

	switch (keycode) {
	case U_T_AUTO:
		if (record->event.pressed && MODS_SHIFT && MODS_CTRL) {
			TOGGLE_FLAG_AND_PRINT(usb_extra_manual, "USB extra port manual mode");
		}

		return false;

	case U_T_AGCR:
		if (record->event.pressed && MODS_SHIFT && MODS_CTRL) {
			TOGGLE_FLAG_AND_PRINT(usb_gcr_auto, "USB GCR auto mode");
		}

		return false;

	case DBG_TOG:
		if (record->event.pressed) {
			TOGGLE_FLAG_AND_PRINT(debug_enable, "Debug mode");
		}

		return false;

	case DBG_MTRX:
		if (record->event.pressed) {
			TOGGLE_FLAG_AND_PRINT(debug_matrix, "Debug matrix");
		}

		return false;

	case DBG_KBD:
		if (record->event.pressed) {
			TOGGLE_FLAG_AND_PRINT(debug_keyboard, "Debug keyboard");
		}

		return false;

	case DBG_MOU:
		if (record->event.pressed) {
			TOGGLE_FLAG_AND_PRINT(debug_mouse, "Debug mouse");
		}

		return false;

	case MD_BOOT:
		if (record->event.pressed) {
			key_timer = timer_read32();
		} else {
			if (timer_elapsed32(key_timer) >= 500) {
				reset_keyboard();
			}
		}

		return false;

	case MAS_TOG:
		if (record->event.pressed) {
			switch (rgb_matrix_get_flags()) {
			case LED_FLAG_ALL: {
				rgb_matrix_set_flags(LED_FLAG_KEYLIGHT);
				rgb_matrix_set_color_all(0, 0, 0);
			}
			break;

			case LED_FLAG_KEYLIGHT: {
				rgb_matrix_set_flags(LED_FLAG_UNDERGLOW);
				rgb_matrix_set_color_all(0, 0, 0);
			}
			break;

			case LED_FLAG_UNDERGLOW: {
				rgb_matrix_set_flags(LED_FLAG_NONE);
				rgb_matrix_disable_noeeprom();
			}
			break;

			default: {
				rgb_matrix_set_flags(LED_FLAG_ALL);
			}
			break;
			}
		}

		return false;

	case MAS_CRM:
		if (record->event.pressed) {
			rgb_matrix_sethsv(32, 160, 255);
		}

		return false;

	case MAS_PRP:
		if (record->event.pressed) {
			rgb_matrix_sethsv(192, 112, 255);
		}

		return false;

	case MAS_RED:
		if (record->event.pressed) {
			rgb_matrix_sethsv(0, 255, 255);
		}

		return false;

	case MAS_GRN:
		if (record->event.pressed) {
			rgb_matrix_sethsv(88, 255, 255);
		}

		return false;

	case MAS_BLU:
		if (record->event.pressed) {
			rgb_matrix_sethsv(168, 255, 255);
		}

		return false;

	case MAS_CYN:
		if (record->event.pressed) {
			rgb_matrix_sethsv(128, 255, 255);
		}

		return false;

	case MAS_MGT:
		if (record->event.pressed) {
			rgb_matrix_sethsv(216, 255, 255);
		}

		return false;

	case MAS_YEL:
		if (record->event.pressed) {
			rgb_matrix_sethsv(40, 255, 255);
		}

		return false;

	case MAS_KEY:
		if (record->event.pressed) {
			rgb_matrix_sethsv(0, 0, 0);
		}

		return false;

	case MAS_WHT:
		if (record->event.pressed) {
			rgb_matrix_sethsv(128, 0, 255);
		}

		return false;

	default:
		return true; //Process all other keycodes normally
	}
}