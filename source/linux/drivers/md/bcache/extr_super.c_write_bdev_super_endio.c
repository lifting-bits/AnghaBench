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
struct cached_dev {int /*<<< orphan*/  sb_write; } ;
struct bio {scalar_t__ bi_status; struct cached_dev* bi_private; } ;

/* Variables and functions */
 int /*<<< orphan*/  bch_count_backing_io_errors (struct cached_dev*,struct bio*) ; 
 int /*<<< orphan*/  closure_put (int /*<<< orphan*/ *) ; 

__attribute__((used)) static void write_bdev_super_endio(struct bio *bio)
{
	struct cached_dev *dc = bio->bi_private;

	if (bio->bi_status)
		bch_count_backing_io_errors(dc, bio);

	closure_put(&dc->sb_write);
}