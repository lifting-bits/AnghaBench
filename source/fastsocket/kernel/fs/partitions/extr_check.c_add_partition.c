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
struct hd_struct {int partno; int /*<<< orphan*/  holder_dir; int /*<<< orphan*/  rcu_head; int /*<<< orphan*/  policy; void* nr_sects; int /*<<< orphan*/  discard_alignment; int /*<<< orphan*/  alignment_offset; void* start_sect; } ;
struct gendisk {TYPE_1__* queue; struct disk_part_tbl* part_tbl; } ;
struct disk_part_tbl {scalar_t__* part; } ;
struct device {int /*<<< orphan*/  kobj; int /*<<< orphan*/  devt; struct device* parent; int /*<<< orphan*/ * type; int /*<<< orphan*/ * class; } ;
typedef  void* sector_t ;
typedef  int /*<<< orphan*/  dev_t ;
struct TYPE_2__ {int /*<<< orphan*/  limits; } ;

/* Variables and functions */
 int ADDPART_FLAG_WHOLEDISK ; 
 int EBUSY ; 
 int ENOMEM ; 
 struct hd_struct* ERR_PTR (int) ; 
 int /*<<< orphan*/  GFP_KERNEL ; 
 int /*<<< orphan*/  INIT_RCU_HEAD (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  KOBJ_ADD ; 
 int /*<<< orphan*/  MKDEV (int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int blk_alloc_devt (struct hd_struct*,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  blk_free_devt (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  block_class ; 
 int /*<<< orphan*/  dev_attr_whole_disk ; 
 int /*<<< orphan*/  dev_get_uevent_suppress (struct device*) ; 
 char* dev_name (struct device*) ; 
 int /*<<< orphan*/  dev_set_name (struct device*,char*,char const*,int) ; 
 int /*<<< orphan*/  dev_set_uevent_suppress (struct device*,int) ; 
 int device_add (struct device*) ; 
 int device_create_file (struct device*,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  device_del (struct device*) ; 
 int /*<<< orphan*/  device_initialize (struct device*) ; 
 int disk_expand_part_tbl (struct gendisk*,int) ; 
 struct device* disk_to_dev (struct gendisk*) ; 
 int /*<<< orphan*/  free_part_stats (struct hd_struct*) ; 
 int /*<<< orphan*/  get_disk_ro (struct gendisk*) ; 
 int /*<<< orphan*/  init_part_stats (struct hd_struct*) ; 
 scalar_t__ isdigit (char const) ; 
 int /*<<< orphan*/  kfree (struct hd_struct*) ; 
 int /*<<< orphan*/  kobject_create_and_add (char*,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  kobject_put (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  kobject_uevent (int /*<<< orphan*/ *,int /*<<< orphan*/ ) ; 
 struct hd_struct* kzalloc (int,int /*<<< orphan*/ ) ; 
 struct device* part_to_dev (struct hd_struct*) ; 
 int /*<<< orphan*/  part_type ; 
 int /*<<< orphan*/  put_device (struct device*) ; 
 int /*<<< orphan*/  queue_limit_alignment_offset (int /*<<< orphan*/ *,void*) ; 
 int /*<<< orphan*/  queue_limit_discard_alignment (int /*<<< orphan*/ *,void*) ; 
 int /*<<< orphan*/  rcu_assign_pointer (scalar_t__,struct hd_struct*) ; 
 int strlen (char const*) ; 

struct hd_struct *add_partition(struct gendisk *disk, int partno,
				sector_t start, sector_t len, int flags)
{
	struct hd_struct *p;
	dev_t devt = MKDEV(0, 0);
	struct device *ddev = disk_to_dev(disk);
	struct device *pdev;
	struct disk_part_tbl *ptbl;
	const char *dname;
	int err;

	err = disk_expand_part_tbl(disk, partno);
	if (err)
		return ERR_PTR(err);
	ptbl = disk->part_tbl;

	if (ptbl->part[partno])
		return ERR_PTR(-EBUSY);

	p = kzalloc(sizeof(*p), GFP_KERNEL);
	if (!p)
		return ERR_PTR(-EBUSY);

	if (!init_part_stats(p)) {
		err = -ENOMEM;
		goto out_free;
	}
	pdev = part_to_dev(p);

	p->start_sect = start;
	p->alignment_offset =
		queue_limit_alignment_offset(&disk->queue->limits, start);
	p->discard_alignment =
		queue_limit_discard_alignment(&disk->queue->limits, start);
	p->nr_sects = len;
	p->partno = partno;
	p->policy = get_disk_ro(disk);

	dname = dev_name(ddev);
	if (isdigit(dname[strlen(dname) - 1]))
		dev_set_name(pdev, "%sp%d", dname, partno);
	else
		dev_set_name(pdev, "%s%d", dname, partno);

	device_initialize(pdev);
	pdev->class = &block_class;
	pdev->type = &part_type;
	pdev->parent = ddev;

	err = blk_alloc_devt(p, &devt);
	if (err)
		goto out_free_stats;
	pdev->devt = devt;

	/* delay uevent until 'holders' subdir is created */
	dev_set_uevent_suppress(pdev, 1);
	err = device_add(pdev);
	if (err)
		goto out_put;

	err = -ENOMEM;
	p->holder_dir = kobject_create_and_add("holders", &pdev->kobj);
	if (!p->holder_dir)
		goto out_del;

	dev_set_uevent_suppress(pdev, 0);
	if (flags & ADDPART_FLAG_WHOLEDISK) {
		err = device_create_file(pdev, &dev_attr_whole_disk);
		if (err)
			goto out_del;
	}

	/* everything is up and running, commence */
	INIT_RCU_HEAD(&p->rcu_head);
	rcu_assign_pointer(ptbl->part[partno], p);

	/* suppress uevent if the disk supresses it */
	if (!dev_get_uevent_suppress(ddev))
		kobject_uevent(&pdev->kobj, KOBJ_ADD);

	return p;

out_free_stats:
	free_part_stats(p);
out_free:
	kfree(p);
	return ERR_PTR(err);
out_del:
	kobject_put(p->holder_dir);
	device_del(pdev);
out_put:
	put_device(pdev);
	blk_free_devt(devt);
	return ERR_PTR(err);
}