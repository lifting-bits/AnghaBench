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
struct nn_ep {int dummy; } ;

/* Variables and functions */
 int nn_bipc_create (struct nn_ep*) ; 

__attribute__((used)) static int nn_ipc_bind (struct nn_ep *ep)
{
    return nn_bipc_create (ep);
}