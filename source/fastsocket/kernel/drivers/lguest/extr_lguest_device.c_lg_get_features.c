#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_2__   TYPE_1__ ;

/* Type definitions */
typedef  int u8 ;
typedef  int u32 ;
struct virtio_device {int dummy; } ;
struct lguest_device_desc {int feature_len; } ;
struct TYPE_2__ {struct lguest_device_desc* desc; } ;

/* Variables and functions */
 int* lg_features (struct lguest_device_desc*) ; 
 unsigned int min (int,int) ; 
 TYPE_1__* to_lgdev (struct virtio_device*) ; 

__attribute__((used)) static u32 lg_get_features(struct virtio_device *vdev)
{
	unsigned int i;
	u32 features = 0;
	struct lguest_device_desc *desc = to_lgdev(vdev)->desc;
	u8 *in_features = lg_features(desc);

	/* We do this the slow but generic way. */
	for (i = 0; i < min(desc->feature_len * 8, 32); i++)
		if (in_features[i / 8] & (1 << (i % 8)))
			features |= (1 << i);

	return features;
}