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
typedef  int /*<<< orphan*/  u8 ;
struct max8952_data {int /*<<< orphan*/  client; } ;

/* Variables and functions */
 int i2c_smbus_read_byte_data (int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 

__attribute__((used)) static int max8952_read_reg(struct max8952_data *max8952, u8 reg)
{
	int ret = i2c_smbus_read_byte_data(max8952->client, reg);

	if (ret > 0)
		ret &= 0xff;

	return ret;
}