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
typedef  int /*<<< orphan*/  U8 ;
typedef  int /*<<< orphan*/  SCI_STATUS ;
typedef  int /*<<< orphan*/  SCI_CONTROLLER_HANDLE_T ;

/* Variables and functions */
 int /*<<< orphan*/  SCI_MAX_PHYS ; 
 int /*<<< orphan*/  SCI_SUCCESS ; 

SCI_STATUS scic_controller_get_max_phys(
   SCI_CONTROLLER_HANDLE_T   controller,
   U8                      * count
)
{
   *count = SCI_MAX_PHYS;
   return SCI_SUCCESS;
}