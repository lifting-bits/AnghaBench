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
typedef  int /*<<< orphan*/  SCI_BASE_OBJECT_T ;
typedef  int /*<<< orphan*/  SCIC_SDS_PHY_T ;

/* Variables and functions */
 int /*<<< orphan*/  SCI_BASE_PHY_STATE_READY ; 
 int /*<<< orphan*/  scic_sds_controller_link_up (int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  scic_sds_phy_get_controller (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  scic_sds_phy_get_port (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  scic_sds_phy_set_base_state_handlers (int /*<<< orphan*/ *,int /*<<< orphan*/ ) ; 

__attribute__((used)) static
void scic_sds_phy_ready_state_enter(
   SCI_BASE_OBJECT_T *object
)
{
   SCIC_SDS_PHY_T *this_phy;
   this_phy = (SCIC_SDS_PHY_T *)object;

   scic_sds_phy_set_base_state_handlers(this_phy, SCI_BASE_PHY_STATE_READY);

   scic_sds_controller_link_up(
      scic_sds_phy_get_controller(this_phy),
      scic_sds_phy_get_port(this_phy),
      this_phy
   );
}