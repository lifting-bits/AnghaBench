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
struct mux_chip {int /*<<< orphan*/  dev; } ;

/* Variables and functions */
 int /*<<< orphan*/  put_device (int /*<<< orphan*/ *) ; 

void mux_chip_free(struct mux_chip *mux_chip)
{
	if (!mux_chip)
		return;

	put_device(&mux_chip->dev);
}