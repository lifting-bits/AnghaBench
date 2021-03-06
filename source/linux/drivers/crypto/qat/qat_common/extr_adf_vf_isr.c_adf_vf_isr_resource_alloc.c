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
struct adf_accel_dev {int dummy; } ;

/* Variables and functions */
 int EFAULT ; 
 scalar_t__ adf_enable_msi (struct adf_accel_dev*) ; 
 scalar_t__ adf_request_msi_irq (struct adf_accel_dev*) ; 
 scalar_t__ adf_setup_bh (struct adf_accel_dev*) ; 
 scalar_t__ adf_setup_pf2vf_bh (struct adf_accel_dev*) ; 
 int /*<<< orphan*/  adf_vf_isr_resource_free (struct adf_accel_dev*) ; 

int adf_vf_isr_resource_alloc(struct adf_accel_dev *accel_dev)
{
	if (adf_enable_msi(accel_dev))
		goto err_out;

	if (adf_setup_pf2vf_bh(accel_dev))
		goto err_out;

	if (adf_setup_bh(accel_dev))
		goto err_out;

	if (adf_request_msi_irq(accel_dev))
		goto err_out;

	return 0;
err_out:
	adf_vf_isr_resource_free(accel_dev);
	return -EFAULT;
}