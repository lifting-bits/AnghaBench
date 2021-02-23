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
struct TYPE_3__ {int /*<<< orphan*/  name; } ;
typedef  TYPE_1__ UnitFileInstallInfo ;

/* Variables and functions */
 int /*<<< orphan*/  assert (TYPE_1__ const*) ; 
 int unit_name_to_prefix (int /*<<< orphan*/ ,char**) ; 

__attribute__((used)) static int specifier_prefix(char specifier, const void *data, const void *userdata, char **ret) {
        const UnitFileInstallInfo *i = userdata;

        assert(i);

        return unit_name_to_prefix(i->name, ret);
}