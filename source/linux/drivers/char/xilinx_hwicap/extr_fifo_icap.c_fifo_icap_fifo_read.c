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
typedef  int /*<<< orphan*/  u32 ;
struct hwicap_drvdata {int /*<<< orphan*/  dev; scalar_t__ base_address; } ;

/* Variables and functions */
 scalar_t__ XHI_RF_OFFSET ; 
 int /*<<< orphan*/  dev_dbg (int /*<<< orphan*/ ,char*,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  in_be32 (scalar_t__) ; 

__attribute__((used)) static inline u32 fifo_icap_fifo_read(struct hwicap_drvdata *drvdata)
{
	u32 data = in_be32(drvdata->base_address + XHI_RF_OFFSET);
	dev_dbg(drvdata->dev, "fifo_read: %x\n", data);
	return data;
}