#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_14__   TYPE_4__ ;
typedef  struct TYPE_13__   TYPE_3__ ;
typedef  struct TYPE_12__   TYPE_2__ ;
typedef  struct TYPE_11__   TYPE_1__ ;

/* Type definitions */
struct TYPE_14__ {TYPE_1__* props; } ;
struct TYPE_13__ {int /*<<< orphan*/  dwData; } ;
struct TYPE_12__ {int /*<<< orphan*/  lDeadZone; } ;
struct TYPE_11__ {int /*<<< orphan*/  lDeadZone; } ;
typedef  TYPE_2__ ObjProps ;
typedef  TYPE_3__* LPCDIPROPDWORD ;
typedef  TYPE_4__ JoystickGenericImpl ;

/* Variables and functions */
 int /*<<< orphan*/  remap_apply (TYPE_4__*,int,TYPE_2__*) ; 
 int /*<<< orphan*/  remap_init (TYPE_4__*,int,TYPE_2__*) ; 

__attribute__((used)) static void remap_deadzone(JoystickGenericImpl *This, int obj, LPCDIPROPDWORD pd)
{
    ObjProps remap_props;
    remap_init(This, obj, &remap_props);

    remap_props.lDeadZone = pd->dwData;

    remap_apply(This, obj, &remap_props);

    /* Store new value */
    This->props[obj].lDeadZone = pd->dwData;
}