#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_10__   TYPE_3__ ;
typedef  struct TYPE_9__   TYPE_2__ ;
typedef  struct TYPE_8__   TYPE_1__ ;

/* Type definitions */
typedef  int /*<<< orphan*/  var_list_t ;
struct TYPE_9__ {TYPE_1__* iface; } ;
struct TYPE_10__ {TYPE_2__ details; } ;
typedef  TYPE_3__ type_t ;
struct TYPE_8__ {int /*<<< orphan*/ * disp_methods; } ;

/* Variables and functions */
 scalar_t__ TYPE_INTERFACE ; 
 int /*<<< orphan*/  assert (int) ; 
 TYPE_3__* type_get_real_type (TYPE_3__ const*) ; 
 scalar_t__ type_get_type (TYPE_3__ const*) ; 

__attribute__((used)) static inline var_list_t *type_dispiface_get_methods(const type_t *type)
{
    type = type_get_real_type(type);
    assert(type_get_type(type) == TYPE_INTERFACE);
    return type->details.iface->disp_methods;
}