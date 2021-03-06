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
struct gendisk {struct dst_node* private_data; } ;
struct dst_node {int dummy; } ;
typedef  int /*<<< orphan*/  fmode_t ;

/* Variables and functions */
 int /*<<< orphan*/  dst_node_put (struct dst_node*) ; 

__attribute__((used)) static int dst_bdev_release(struct gendisk *disk, fmode_t mode)
{
	struct dst_node *n = disk->private_data;

	dst_node_put(n);
	return 0;
}