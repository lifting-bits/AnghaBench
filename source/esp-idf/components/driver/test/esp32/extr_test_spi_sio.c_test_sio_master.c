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
 int /*<<< orphan*/  test_sio_master_round (int) ; 
 int /*<<< orphan*/  unity_send_signal (char*) ; 

void test_sio_master(void)
{
    test_sio_master_round(true);
    unity_send_signal("master ready");
    test_sio_master_round(false);
}