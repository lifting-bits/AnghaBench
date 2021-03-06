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
typedef  int /*<<< orphan*/  ENGINE ;

/* Variables and functions */
 int /*<<< orphan*/  dh_table ; 
 int /*<<< orphan*/  dummy_nid ; 
 int /*<<< orphan*/ * engine_table_select (int /*<<< orphan*/ *,int /*<<< orphan*/ ) ; 

ENGINE *ENGINE_get_default_EC(void)
{
    return engine_table_select(&dh_table, dummy_nid);
}