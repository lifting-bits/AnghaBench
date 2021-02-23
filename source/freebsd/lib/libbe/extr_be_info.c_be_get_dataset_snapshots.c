#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_6__   TYPE_2__ ;
typedef  struct TYPE_5__   TYPE_1__ ;

/* Type definitions */
typedef  int /*<<< orphan*/  zfs_handle_t ;
struct TYPE_5__ {int single_object; int /*<<< orphan*/ * list; TYPE_2__* lbh; } ;
typedef  TYPE_1__ prop_data_t ;
typedef  int /*<<< orphan*/  nvlist_t ;
struct TYPE_6__ {int /*<<< orphan*/  lzh; } ;
typedef  TYPE_2__ libbe_handle_t ;

/* Variables and functions */
 int BE_ERR_ZFSOPEN ; 
 int /*<<< orphan*/  ZFS_TYPE_FILESYSTEM ; 
 int snapshot_proplist_update (int /*<<< orphan*/ *,TYPE_1__*) ; 
 int /*<<< orphan*/  zfs_close (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/ * zfs_open (int /*<<< orphan*/ ,char const*,int /*<<< orphan*/ ) ; 

int
be_get_dataset_snapshots(libbe_handle_t *lbh, const char *name, nvlist_t *props)
{
	zfs_handle_t *ds_hdl;
	prop_data_t data;
	int ret;

	data.lbh = lbh;
	data.list = props;
	data.single_object = false;
	if ((ds_hdl = zfs_open(lbh->lzh, name,
	    ZFS_TYPE_FILESYSTEM)) == NULL)
		return (BE_ERR_ZFSOPEN);

	ret = snapshot_proplist_update(ds_hdl, &data);
	zfs_close(ds_hdl);
	return (ret);
}