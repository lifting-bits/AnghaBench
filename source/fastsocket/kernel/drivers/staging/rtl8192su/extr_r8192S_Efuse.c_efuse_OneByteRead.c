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
typedef  int u16 ;
struct net_device {int dummy; } ;

/* Variables and functions */
 scalar_t__ EFUSE_CTRL ; 
 int FALSE ; 
 int TRUE ; 
 int read_nic_byte (struct net_device*,scalar_t__) ; 
 int /*<<< orphan*/  write_nic_byte (struct net_device*,scalar_t__,int) ; 

__attribute__((used)) static	u8
efuse_OneByteRead(struct net_device* dev, u16 addr,u8 *data)
{
	u8 tmpidx = 0;
	u8 bResult;

	// -----------------e-fuse reg ctrl ---------------------------------
	//address
	write_nic_byte(dev, EFUSE_CTRL+1, (u8)(addr&0xff));
	write_nic_byte(dev, EFUSE_CTRL+2, ((u8)((addr>>8) &0x03) ) |
	(read_nic_byte(dev, EFUSE_CTRL+2)&0xFC ));

	write_nic_byte(dev, EFUSE_CTRL+3,  0x72);//read cmd

	while(!(0x80 &read_nic_byte(dev, EFUSE_CTRL+3))&&(tmpidx<100))
	{
		tmpidx++;
	}
	if(tmpidx<100)
	{
		*data=read_nic_byte(dev, EFUSE_CTRL);
		bResult = TRUE;
	}
	else
	{
		*data = 0xff;
		bResult = FALSE;
	}
	return bResult;
}