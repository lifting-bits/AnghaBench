#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_4__   TYPE_2__ ;
typedef  struct TYPE_3__   TYPE_1__ ;

/* Type definitions */
struct TYPE_3__ {int style; } ;
struct TYPE_4__ {TYPE_1__ format; } ;
struct sst_hsw_stream {TYPE_2__ request; scalar_t__ commited; } ;
struct sst_hsw {int /*<<< orphan*/  dev; } ;
typedef  enum sst_hsw_interleaving { ____Placeholder_sst_hsw_interleaving } sst_hsw_interleaving ;

/* Variables and functions */
 int EINVAL ; 
 int /*<<< orphan*/  dev_err (int /*<<< orphan*/ ,char*) ; 

int sst_hsw_stream_set_style(struct sst_hsw *hsw,
	struct sst_hsw_stream *stream, enum sst_hsw_interleaving style)
{
	if (stream->commited) {
		dev_err(hsw->dev, "error: stream committed for set style\n");
		return -EINVAL;
	}

	stream->request.format.style = style;
	return 0;
}