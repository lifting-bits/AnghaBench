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
struct v4l2_subdev {int dummy; } ;
struct v4l2_dbg_chip_ident {int dummy; } ;
struct msp_state {int rev1; int rev2; int /*<<< orphan*/  ident; } ;
struct i2c_client {int dummy; } ;

/* Variables and functions */
 struct msp_state* to_state (struct v4l2_subdev*) ; 
 int v4l2_chip_ident_i2c_client (struct i2c_client*,struct v4l2_dbg_chip_ident*,int /*<<< orphan*/ ,int) ; 
 struct i2c_client* v4l2_get_subdevdata (struct v4l2_subdev*) ; 

__attribute__((used)) static int msp_g_chip_ident(struct v4l2_subdev *sd, struct v4l2_dbg_chip_ident *chip)
{
	struct msp_state *state = to_state(sd);
	struct i2c_client *client = v4l2_get_subdevdata(sd);

	return v4l2_chip_ident_i2c_client(client, chip, state->ident,
			(state->rev1 << 16) | state->rev2);
}