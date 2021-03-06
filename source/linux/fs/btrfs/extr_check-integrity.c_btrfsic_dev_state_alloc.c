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
struct btrfsic_dev_state {int dummy; } ;

/* Variables and functions */
 int /*<<< orphan*/  GFP_NOFS ; 
 int /*<<< orphan*/  btrfsic_dev_state_init (struct btrfsic_dev_state*) ; 
 struct btrfsic_dev_state* kzalloc (int,int /*<<< orphan*/ ) ; 

__attribute__((used)) static struct btrfsic_dev_state *btrfsic_dev_state_alloc(void)
{
	struct btrfsic_dev_state *ds;

	ds = kzalloc(sizeof(*ds), GFP_NOFS);
	if (NULL != ds)
		btrfsic_dev_state_init(ds);

	return ds;
}