#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_2__   TYPE_1__ ;

/* Type definitions */
typedef  int /*<<< orphan*/  uint32_t ;
struct vo {TYPE_1__* x11; } ;
struct TYPE_2__ {int /*<<< orphan*/  display; } ;

/* Variables and functions */
 int /*<<< orphan*/  MP_VERBOSE (struct vo*,char*,char const*,int) ; 
 int None ; 
 int VO_FALSE ; 
 int VO_TRUE ; 
 int /*<<< orphan*/  XvSetPortAttribute (int /*<<< orphan*/ ,int /*<<< orphan*/ ,int,int) ; 
 int xv_find_atom (struct vo*,int /*<<< orphan*/ ,char const*,int,int*,int*) ; 

__attribute__((used)) static int xv_set_eq(struct vo *vo, uint32_t xv_port, const char *name,
                     int value)
{
    MP_VERBOSE(vo, "xv_set_eq called! (%s, %d)\n", name, value);

    int min, max;
    int atom = xv_find_atom(vo, xv_port, name, false, &min, &max);
    if (atom != None) {
        // -100 -> min
        //   0  -> (max+min)/2
        // +100 -> max
        int port_value = (value + 100) * (max - min) / 200 + min;
        XvSetPortAttribute(vo->x11->display, xv_port, atom, port_value);
        return VO_TRUE;
    }
    return VO_FALSE;
}