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
 int /*<<< orphan*/  engine_table_cleanup (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  pkey_asn1_meth_table ; 

__attribute__((used)) static void engine_unregister_all_pkey_asn1_meths(void)
{
    engine_table_cleanup(&pkey_asn1_meth_table);
}