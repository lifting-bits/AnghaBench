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
 int /*<<< orphan*/  SQLITE_CONFIG_MULTITHREAD ; 
 int sqlite3_config (int /*<<< orphan*/ ) ; 

int sqlite3_config_multithread(void)
{
    return sqlite3_config(SQLITE_CONFIG_MULTITHREAD);
}