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
typedef  int /*<<< orphan*/  layer_state_t ;

/* Variables and functions */
 int /*<<< orphan*/  BLUE_LED ; 
#define  FRENCH_LAYER 131 
 int /*<<< orphan*/  GREEN_LED ; 
#define  MEDIA_LAYER 130 
#define  NORMAL_LAYER 129 
 int /*<<< orphan*/  RED_LED ; 
#define  TBD_LAYER2 128 
 int biton32 (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  turn_off_leds () ; 
 int /*<<< orphan*/  turn_on_led (int /*<<< orphan*/ ) ; 

layer_state_t layer_state_set_user(layer_state_t state)
{
    turn_off_leds();

    switch (biton32(state))
    {
    case NORMAL_LAYER:
	break;

    case MEDIA_LAYER:
	turn_on_led(RED_LED);
	break;

    case TBD_LAYER2:
	turn_on_led(BLUE_LED);
	break;

    case FRENCH_LAYER:
	turn_on_led(GREEN_LED);
	break;
	}
    return state;
}