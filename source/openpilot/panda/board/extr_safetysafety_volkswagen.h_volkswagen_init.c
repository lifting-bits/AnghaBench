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
typedef  int /*<<< orphan*/  int16_t ;

/* Variables and functions */
 int /*<<< orphan*/  UNUSED (int /*<<< orphan*/ ) ; 
 scalar_t__ controls_allowed ; 

__attribute__((used)) static void volkswagen_init(int16_t param) {
  UNUSED(param); // May use param in the future to indicate MQB vs PQ35/PQ46/NMS vs MLB, or wiring configuration.
  controls_allowed = 0;
}