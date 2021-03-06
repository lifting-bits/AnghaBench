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
struct sg_table {int dummy; } ;
struct drm_gem_object {int dummy; } ;
struct drm_device {int dummy; } ;
struct dma_buf_attachment {int /*<<< orphan*/  dmabuf; } ;

/* Variables and functions */
 struct drm_gem_object* msm_gem_import (struct drm_device*,int /*<<< orphan*/ ,struct sg_table*) ; 

struct drm_gem_object *msm_gem_prime_import_sg_table(struct drm_device *dev,
		struct dma_buf_attachment *attach, struct sg_table *sg)
{
	return msm_gem_import(dev, attach->dmabuf, sg);
}