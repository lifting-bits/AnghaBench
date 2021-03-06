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
typedef  int u8 ;
struct regulator_dev {int dummy; } ;
struct lp872x {int dummy; } ;
typedef  enum lp872x_regulator_id { ____Placeholder_lp872x_regulator_id } lp872x_regulator_id ;

/* Variables and functions */
 unsigned int EINVAL ; 
 int LP8720_BUCK_FPWM_M ; 
 int LP8720_BUCK_VOUT2 ; 
#define  LP8720_ID_BUCK 130 
 int LP8725_BUCK1_FPWM_M ; 
 int LP8725_BUCK2_FPWM_M ; 
 int LP8725_BUCK_CTRL ; 
#define  LP8725_ID_BUCK1 129 
#define  LP8725_ID_BUCK2 128 
 unsigned int REGULATOR_MODE_FAST ; 
 unsigned int REGULATOR_MODE_NORMAL ; 
 int lp872x_read_byte (struct lp872x*,int,int*) ; 
 struct lp872x* rdev_get_drvdata (struct regulator_dev*) ; 
 int rdev_get_id (struct regulator_dev*) ; 

__attribute__((used)) static unsigned int lp872x_buck_get_mode(struct regulator_dev *rdev)
{
	struct lp872x *lp = rdev_get_drvdata(rdev);
	enum lp872x_regulator_id buck = rdev_get_id(rdev);
	u8 addr, mask, val;
	int ret;

	switch (buck) {
	case LP8720_ID_BUCK:
		addr = LP8720_BUCK_VOUT2;
		mask = LP8720_BUCK_FPWM_M;
		break;
	case LP8725_ID_BUCK1:
		addr = LP8725_BUCK_CTRL;
		mask = LP8725_BUCK1_FPWM_M;
		break;
	case LP8725_ID_BUCK2:
		addr = LP8725_BUCK_CTRL;
		mask = LP8725_BUCK2_FPWM_M;
		break;
	default:
		return -EINVAL;
	}

	ret = lp872x_read_byte(lp, addr, &val);
	if (ret)
		return ret;

	return val & mask ? REGULATOR_MODE_FAST : REGULATOR_MODE_NORMAL;
}