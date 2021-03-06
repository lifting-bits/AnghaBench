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
struct soc_tplg {int /*<<< orphan*/  dev; } ;
struct TYPE_2__ {int /*<<< orphan*/  info; int /*<<< orphan*/  put; int /*<<< orphan*/  get; } ;
struct snd_soc_tplg_ctl_hdr {TYPE_1__ ops; } ;

/* Variables and functions */
 int /*<<< orphan*/  dev_err (int /*<<< orphan*/ ,char*,char const*,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  soc_tplg_get_offset (struct soc_tplg*) ; 

__attribute__((used)) static inline void soc_control_err(struct soc_tplg *tplg,
	struct snd_soc_tplg_ctl_hdr *hdr, const char *name)
{
	dev_err(tplg->dev,
		"ASoC: no complete mixer IO handler for %s type (g,p,i) %d:%d:%d at 0x%lx\n",
		name, hdr->ops.get, hdr->ops.put, hdr->ops.info,
		soc_tplg_get_offset(tplg));
}