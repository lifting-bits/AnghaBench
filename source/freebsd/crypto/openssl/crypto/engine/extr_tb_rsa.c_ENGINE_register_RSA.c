#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_4__   TYPE_1__ ;

/* Type definitions */
struct TYPE_4__ {scalar_t__ rsa_meth; } ;
typedef  TYPE_1__ ENGINE ;

/* Variables and functions */
 int /*<<< orphan*/  dummy_nid ; 
 int engine_table_register (int /*<<< orphan*/ *,int /*<<< orphan*/ ,TYPE_1__*,int /*<<< orphan*/ *,int,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  engine_unregister_all_RSA ; 
 int /*<<< orphan*/  rsa_table ; 

int ENGINE_register_RSA(ENGINE *e)
{
    if (e->rsa_meth)
        return engine_table_register(&rsa_table,
                                     engine_unregister_all_RSA, e, &dummy_nid,
                                     1, 0);
    return 1;
}