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
struct al_serdes_grp_obj {int dummy; } ;
typedef  enum al_serdes_reg_page { ____Placeholder_al_serdes_reg_page } al_serdes_reg_page ;
typedef  enum al_serdes_lane { ____Placeholder_al_serdes_lane } al_serdes_lane ;

/* Variables and functions */
 int /*<<< orphan*/  AL_SRDS_REG_TYPE_PMA ; 
 int /*<<< orphan*/  al_serdes_reg_write (struct al_serdes_grp_obj*,int,int /*<<< orphan*/ ,int,int) ; 

__attribute__((used)) static void al_serdes_lane_rx_rate_change_sw_flow_en(
	struct al_serdes_grp_obj	*obj,
	enum al_serdes_lane	lane)
{
	al_serdes_reg_write(obj, (enum al_serdes_reg_page)lane, AL_SRDS_REG_TYPE_PMA, 201, 0xfc);
	al_serdes_reg_write(obj, (enum al_serdes_reg_page)lane, AL_SRDS_REG_TYPE_PMA, 202, 0xff);
	al_serdes_reg_write(obj, (enum al_serdes_reg_page)lane, AL_SRDS_REG_TYPE_PMA, 203, 0xff);
	al_serdes_reg_write(obj, (enum al_serdes_reg_page)lane, AL_SRDS_REG_TYPE_PMA, 204, 0xff);
	al_serdes_reg_write(obj, (enum al_serdes_reg_page)lane, AL_SRDS_REG_TYPE_PMA, 205, 0x7f);
	al_serdes_reg_write(obj, (enum al_serdes_reg_page)lane, AL_SRDS_REG_TYPE_PMA, 205, 0xff);
}