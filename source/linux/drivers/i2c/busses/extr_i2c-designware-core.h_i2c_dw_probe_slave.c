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
struct dw_i2c_dev {int dummy; } ;

/* Variables and functions */
 int EINVAL ; 

__attribute__((used)) static inline int i2c_dw_probe_slave(struct dw_i2c_dev *dev) { return -EINVAL; }