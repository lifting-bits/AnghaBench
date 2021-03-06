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
typedef  int /*<<< orphan*/  u32 ;
struct c4iw_id_table {int dummy; } ;

/* Variables and functions */
 int /*<<< orphan*/  c4iw_id_free (struct c4iw_id_table*,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  pr_debug (char*,int /*<<< orphan*/ ) ; 

void c4iw_put_resource(struct c4iw_id_table *id_table, u32 entry)
{
	pr_debug("entry 0x%x\n", entry);
	c4iw_id_free(id_table, entry);
}