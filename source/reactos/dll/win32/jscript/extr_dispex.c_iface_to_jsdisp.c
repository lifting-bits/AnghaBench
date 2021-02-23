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
typedef  int /*<<< orphan*/  jsdisp_t ;
struct TYPE_3__ {int /*<<< orphan*/  const* lpVtbl; } ;
typedef  int /*<<< orphan*/  IDispatchVtbl ;
typedef  int /*<<< orphan*/  IDispatchEx ;
typedef  TYPE_1__ IDispatch ;

/* Variables and functions */
 int /*<<< orphan*/  DispatchExVtbl ; 
 int /*<<< orphan*/  impl_from_IDispatchEx (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/ * jsdisp_addref (int /*<<< orphan*/ ) ; 

jsdisp_t *iface_to_jsdisp(IDispatch *iface)
{
    return iface->lpVtbl == (const IDispatchVtbl*)&DispatchExVtbl
        ? jsdisp_addref( impl_from_IDispatchEx((IDispatchEx*)iface))
        : NULL;
}