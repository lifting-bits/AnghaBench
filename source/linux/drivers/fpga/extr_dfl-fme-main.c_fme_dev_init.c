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
struct platform_device {int /*<<< orphan*/  dev; } ;
struct dfl_fme {struct dfl_feature_platform_data* pdata; } ;
struct dfl_feature_platform_data {int /*<<< orphan*/  lock; } ;

/* Variables and functions */
 int ENOMEM ; 
 int /*<<< orphan*/  GFP_KERNEL ; 
 struct dfl_feature_platform_data* dev_get_platdata (int /*<<< orphan*/ *) ; 
 struct dfl_fme* devm_kzalloc (int /*<<< orphan*/ *,int,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  dfl_fpga_pdata_set_private (struct dfl_feature_platform_data*,struct dfl_fme*) ; 
 int /*<<< orphan*/  mutex_lock (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  mutex_unlock (int /*<<< orphan*/ *) ; 

__attribute__((used)) static int fme_dev_init(struct platform_device *pdev)
{
	struct dfl_feature_platform_data *pdata = dev_get_platdata(&pdev->dev);
	struct dfl_fme *fme;

	fme = devm_kzalloc(&pdev->dev, sizeof(*fme), GFP_KERNEL);
	if (!fme)
		return -ENOMEM;

	fme->pdata = pdata;

	mutex_lock(&pdata->lock);
	dfl_fpga_pdata_set_private(pdata, fme);
	mutex_unlock(&pdata->lock);

	return 0;
}