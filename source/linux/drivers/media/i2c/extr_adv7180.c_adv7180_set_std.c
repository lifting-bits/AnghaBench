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
struct adv7180_state {unsigned int input; } ;

/* Variables and functions */
 int /*<<< orphan*/  ADV7180_REG_INPUT_CONTROL ; 
 int adv7180_write (struct adv7180_state*,int /*<<< orphan*/ ,unsigned int) ; 

__attribute__((used)) static int adv7180_set_std(struct adv7180_state *state, unsigned int std)
{
	return adv7180_write(state, ADV7180_REG_INPUT_CONTROL,
		(std << 4) | state->input);
}