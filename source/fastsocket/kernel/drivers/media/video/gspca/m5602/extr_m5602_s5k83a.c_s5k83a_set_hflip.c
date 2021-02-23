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
typedef  scalar_t__ u8 ;
struct sd {struct s5k83a_priv* sensor_priv; } ;
struct s5k83a_priv {int* settings; } ;
struct gspca_dev {int dummy; } ;
typedef  int __s32 ;

/* Variables and functions */
 size_t HFLIP_IDX ; 
 int s5k83a_get_rotation (struct sd*,scalar_t__*) ; 
 int /*<<< orphan*/  s5k83a_get_vflip (struct gspca_dev*,int*) ; 
 int s5k83a_set_flip_real (struct gspca_dev*,int,int) ; 

__attribute__((used)) static int s5k83a_set_hflip(struct gspca_dev *gspca_dev, __s32 val)
{
	int err;
	u8 reg;
	__s32 vflip;
	struct sd *sd = (struct sd *) gspca_dev;
	struct s5k83a_priv *sens_priv = sd->sensor_priv;

	sens_priv->settings[HFLIP_IDX] = val;

	s5k83a_get_vflip(gspca_dev, &vflip);

	err = s5k83a_get_rotation(sd, &reg);
	if (err < 0)
		return err;
	if (reg) {
		val = !val;
		vflip = !vflip;
	}

	err = s5k83a_set_flip_real(gspca_dev, vflip, val);
	return err;
}