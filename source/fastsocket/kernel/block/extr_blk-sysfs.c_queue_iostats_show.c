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
struct request_queue {int dummy; } ;
typedef  int /*<<< orphan*/  ssize_t ;

/* Variables and functions */
 int /*<<< orphan*/  blk_queue_io_stat (struct request_queue*) ; 
 int /*<<< orphan*/  queue_var_show (int /*<<< orphan*/ ,char*) ; 

__attribute__((used)) static ssize_t queue_iostats_show(struct request_queue *q, char *page)
{
	return queue_var_show(blk_queue_io_stat(q), page);
}