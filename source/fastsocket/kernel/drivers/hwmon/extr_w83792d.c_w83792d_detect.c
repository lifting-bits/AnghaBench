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
struct i2c_client {unsigned short addr; struct i2c_adapter* adapter; } ;
struct i2c_board_info {int /*<<< orphan*/  type; } ;
struct i2c_adapter {int /*<<< orphan*/  dev; } ;

/* Variables and functions */
 int ENODEV ; 
 int /*<<< orphan*/  I2C_FUNC_SMBUS_BYTE_DATA ; 
 int /*<<< orphan*/  I2C_NAME_SIZE ; 
 int /*<<< orphan*/  W83792D_REG_BANK ; 
 int /*<<< orphan*/  W83792D_REG_CHIPMAN ; 
 int /*<<< orphan*/  W83792D_REG_CONFIG ; 
 int /*<<< orphan*/  W83792D_REG_I2C_ADDR ; 
 int /*<<< orphan*/  W83792D_REG_WCHIPID ; 
 int /*<<< orphan*/  dev_warn (int /*<<< orphan*/ *,char*,int /*<<< orphan*/ ,unsigned short) ; 
 int /*<<< orphan*/  i2c_adapter_id (struct i2c_adapter*) ; 
 int /*<<< orphan*/  i2c_check_functionality (struct i2c_adapter*,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  strlcpy (int /*<<< orphan*/ ,char*,int /*<<< orphan*/ ) ; 
 int w83792d ; 
 int w83792d_read_value (struct i2c_client*,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  w83792d_write_value (struct i2c_client*,int /*<<< orphan*/ ,int) ; 

__attribute__((used)) static int
w83792d_detect(struct i2c_client *client, int kind, struct i2c_board_info *info)
{
	struct i2c_adapter *adapter = client->adapter;
	int val1, val2;
	unsigned short address = client->addr;

	if (!i2c_check_functionality(adapter, I2C_FUNC_SMBUS_BYTE_DATA)) {
		return -ENODEV;
	}

	/* The w83792d may be stuck in some other bank than bank 0. This may
	   make reading other information impossible. Specify a force=... or
	   force_*=... parameter, and the Winbond will be reset to the right
	   bank. */
	if (kind < 0) {
		if (w83792d_read_value(client, W83792D_REG_CONFIG) & 0x80) {
			return -ENODEV;
		}
		val1 = w83792d_read_value(client, W83792D_REG_BANK);
		val2 = w83792d_read_value(client, W83792D_REG_CHIPMAN);
		/* Check for Winbond ID if in bank 0 */
		if (!(val1 & 0x07)) {  /* is Bank0 */
			if (((!(val1 & 0x80)) && (val2 != 0xa3)) ||
			     ((val1 & 0x80) && (val2 != 0x5c))) {
				return -ENODEV;
			}
		}
		/* If Winbond chip, address of chip and W83792D_REG_I2C_ADDR
		   should match */
		if (w83792d_read_value(client,
					W83792D_REG_I2C_ADDR) != address) {
			return -ENODEV;
		}
	}

	/* We have either had a force parameter, or we have already detected the
	   Winbond. Put it now into bank 0 and Vendor ID High Byte */
	w83792d_write_value(client,
			    W83792D_REG_BANK,
			    (w83792d_read_value(client,
				W83792D_REG_BANK) & 0x78) | 0x80);

	/* Determine the chip type. */
	if (kind <= 0) {
		/* get vendor ID */
		val2 = w83792d_read_value(client, W83792D_REG_CHIPMAN);
		if (val2 != 0x5c) {  /* the vendor is NOT Winbond */
			return -ENODEV;
		}
		val1 = w83792d_read_value(client, W83792D_REG_WCHIPID);
		if (val1 == 0x7a) {
			kind = w83792d;
		} else {
			if (kind == 0)
				dev_warn(&adapter->dev,
					"w83792d: Ignoring 'force' parameter for"
					" unknown chip at adapter %d, address"
					" 0x%02x\n", i2c_adapter_id(adapter),
					address);
			return -ENODEV;
		}
	}

	strlcpy(info->type, "w83792d", I2C_NAME_SIZE);

	return 0;
}