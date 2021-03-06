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
struct dm_clone_metadata {int /*<<< orphan*/  bm; int /*<<< orphan*/  bdev; } ;

/* Variables and functions */
 int /*<<< orphan*/  DMERR (char*) ; 
 int /*<<< orphan*/  DM_CLONE_MAX_CONCURRENT_LOCKS ; 
 int DM_CLONE_METADATA_BLOCK_SIZE ; 
 scalar_t__ IS_ERR (int /*<<< orphan*/ ) ; 
 int PTR_ERR (int /*<<< orphan*/ ) ; 
 int SECTOR_SHIFT ; 
 int __open_or_format_metadata (struct dm_clone_metadata*,int) ; 
 int /*<<< orphan*/  dm_block_manager_create (int /*<<< orphan*/ ,int,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  dm_block_manager_destroy (int /*<<< orphan*/ ) ; 

__attribute__((used)) static int __create_persistent_data_structures(struct dm_clone_metadata *cmd,
					       bool may_format_device)
{
	int r;

	/* Create block manager */
	cmd->bm = dm_block_manager_create(cmd->bdev,
					 DM_CLONE_METADATA_BLOCK_SIZE << SECTOR_SHIFT,
					 DM_CLONE_MAX_CONCURRENT_LOCKS);
	if (IS_ERR(cmd->bm)) {
		DMERR("Failed to create block manager");
		return PTR_ERR(cmd->bm);
	}

	r = __open_or_format_metadata(cmd, may_format_device);
	if (r)
		dm_block_manager_destroy(cmd->bm);

	return r;
}