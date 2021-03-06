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
struct vlapic {int dummy; } ;

/* Variables and functions */
 int /*<<< orphan*/  M_VLAPIC ; 
 int /*<<< orphan*/  free (struct vlapic*,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  vlapic_cleanup (struct vlapic*) ; 

__attribute__((used)) static void
vmx_vlapic_cleanup(void *arg, struct vlapic *vlapic)
{

	vlapic_cleanup(vlapic);
	free(vlapic, M_VLAPIC);
}