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
 int /*<<< orphan*/  GPIOA ; 
 int /*<<< orphan*/  GPIOB ; 
 int /*<<< orphan*/  PAL_MODE_INPUT_PULLUP ; 
 int /*<<< orphan*/  palSetPadMode (int /*<<< orphan*/ ,int,int /*<<< orphan*/ ) ; 

__attribute__((used)) static void  init_cols(void){
  palSetPadMode(GPIOA, 5, PAL_MODE_INPUT_PULLUP);
  palSetPadMode(GPIOA, 15, PAL_MODE_INPUT_PULLUP);
  palSetPadMode(GPIOA, 10, PAL_MODE_INPUT_PULLUP);
  palSetPadMode(GPIOA, 9, PAL_MODE_INPUT_PULLUP);
  palSetPadMode(GPIOA, 8, PAL_MODE_INPUT_PULLUP);
  palSetPadMode(GPIOB, 15, PAL_MODE_INPUT_PULLUP);
  palSetPadMode(GPIOB, 14, PAL_MODE_INPUT_PULLUP);
  palSetPadMode(GPIOB, 13, PAL_MODE_INPUT_PULLUP);
  palSetPadMode(GPIOB, 12, PAL_MODE_INPUT_PULLUP);
  palSetPadMode(GPIOB, 11, PAL_MODE_INPUT_PULLUP);
  palSetPadMode(GPIOB, 10, PAL_MODE_INPUT_PULLUP);
  palSetPadMode(GPIOB, 1, PAL_MODE_INPUT_PULLUP);
  palSetPadMode(GPIOB, 0, PAL_MODE_INPUT_PULLUP);
  palSetPadMode(GPIOA, 7, PAL_MODE_INPUT_PULLUP);
  palSetPadMode(GPIOA, 6, PAL_MODE_INPUT_PULLUP);
}