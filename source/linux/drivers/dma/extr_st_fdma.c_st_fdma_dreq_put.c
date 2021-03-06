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
struct st_fdma_dev {int /*<<< orphan*/  dreq_mask; int /*<<< orphan*/  dev; } ;
struct st_fdma_chan {int /*<<< orphan*/  dreq_line; struct st_fdma_dev* fdev; } ;

/* Variables and functions */
 int /*<<< orphan*/  clear_bit (int /*<<< orphan*/ ,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  dev_dbg (int /*<<< orphan*/ ,char*,int /*<<< orphan*/ ) ; 

__attribute__((used)) static void st_fdma_dreq_put(struct st_fdma_chan *fchan)
{
	struct st_fdma_dev *fdev = fchan->fdev;

	dev_dbg(fdev->dev, "put dreq_line:%#x\n", fchan->dreq_line);
	clear_bit(fchan->dreq_line, &fdev->dreq_mask);
}