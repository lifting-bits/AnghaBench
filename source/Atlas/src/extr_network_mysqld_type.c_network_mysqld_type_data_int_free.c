#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_3__   TYPE_1__ ;

/* Type definitions */
struct TYPE_3__ {int /*<<< orphan*/ * data; } ;
typedef  TYPE_1__ network_mysqld_type_t ;

/* Variables and functions */
 int /*<<< orphan*/  network_mysqld_type_int_free (int /*<<< orphan*/ *) ; 

__attribute__((used)) static void network_mysqld_type_data_int_free(network_mysqld_type_t *type) {
	if (NULL == type) return;
	if (NULL == type->data) return;

	network_mysqld_type_int_free(type->data);
}