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

/* Variables and functions */
 int /*<<< orphan*/  NORMAL ; 
 int /*<<< orphan*/  NORMAL_THUMB_RETURN_COMMAND ; 
 int /*<<< orphan*/  layer_move (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  layer_set (int,int /*<<< orphan*/ ) ; 

__attribute__((used)) static void set_normal(void) {
  layer_move(NORMAL);

#ifdef DATAHAND_THUMB_RETURN_COMMAND
  layer_set(true, NORMAL_THUMB_RETURN_COMMAND);
#endif

  /* Then call layer_set to update LEDs. */
  layer_set(true, NORMAL);
}