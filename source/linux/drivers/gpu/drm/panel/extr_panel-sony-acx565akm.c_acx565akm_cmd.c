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
struct acx565akm_panel {int dummy; } ;

/* Variables and functions */
 int /*<<< orphan*/  acx565akm_transfer (struct acx565akm_panel*,int,int /*<<< orphan*/ *,int /*<<< orphan*/ ,int /*<<< orphan*/ *,int /*<<< orphan*/ ) ; 

__attribute__((used)) static inline void acx565akm_cmd(struct acx565akm_panel *lcd, int cmd)
{
	acx565akm_transfer(lcd, cmd, NULL, 0, NULL, 0);
}