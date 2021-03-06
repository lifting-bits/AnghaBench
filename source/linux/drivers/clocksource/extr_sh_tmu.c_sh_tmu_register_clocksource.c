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
struct clocksource {char const* name; int rating; int /*<<< orphan*/  flags; int /*<<< orphan*/  mask; int /*<<< orphan*/  resume; int /*<<< orphan*/  suspend; int /*<<< orphan*/  disable; int /*<<< orphan*/  enable; int /*<<< orphan*/  read; } ;
struct sh_tmu_channel {TYPE_2__* tmu; int /*<<< orphan*/  index; struct clocksource cs; } ;
struct TYPE_4__ {int /*<<< orphan*/  rate; TYPE_1__* pdev; } ;
struct TYPE_3__ {int /*<<< orphan*/  dev; } ;

/* Variables and functions */
 int /*<<< orphan*/  CLOCKSOURCE_MASK (int) ; 
 int /*<<< orphan*/  CLOCK_SOURCE_IS_CONTINUOUS ; 
 int /*<<< orphan*/  clocksource_register_hz (struct clocksource*,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  dev_info (int /*<<< orphan*/ *,char*,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  sh_tmu_clocksource_disable ; 
 int /*<<< orphan*/  sh_tmu_clocksource_enable ; 
 int /*<<< orphan*/  sh_tmu_clocksource_read ; 
 int /*<<< orphan*/  sh_tmu_clocksource_resume ; 
 int /*<<< orphan*/  sh_tmu_clocksource_suspend ; 

__attribute__((used)) static int sh_tmu_register_clocksource(struct sh_tmu_channel *ch,
				       const char *name)
{
	struct clocksource *cs = &ch->cs;

	cs->name = name;
	cs->rating = 200;
	cs->read = sh_tmu_clocksource_read;
	cs->enable = sh_tmu_clocksource_enable;
	cs->disable = sh_tmu_clocksource_disable;
	cs->suspend = sh_tmu_clocksource_suspend;
	cs->resume = sh_tmu_clocksource_resume;
	cs->mask = CLOCKSOURCE_MASK(32);
	cs->flags = CLOCK_SOURCE_IS_CONTINUOUS;

	dev_info(&ch->tmu->pdev->dev, "ch%u: used as clock source\n",
		 ch->index);

	clocksource_register_hz(cs, ch->tmu->rate);
	return 0;
}