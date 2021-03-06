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
struct isp1301 {int /*<<< orphan*/  client; } ;

/* Variables and functions */
 scalar_t__ i2c_smbus_read_byte_data (int /*<<< orphan*/ ,scalar_t__) ; 

__attribute__((used)) static inline u8
isp1301_get_u8(struct isp1301 *isp, u8 reg)
{
	return i2c_smbus_read_byte_data(isp->client, reg + 0);
}