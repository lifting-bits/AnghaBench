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
struct pinctrl_dev {int dummy; } ;
struct amd_gpio {TYPE_1__* groups; } ;
struct TYPE_2__ {char const* name; } ;

/* Variables and functions */
 struct amd_gpio* pinctrl_dev_get_drvdata (struct pinctrl_dev*) ; 

__attribute__((used)) static const char *amd_get_group_name(struct pinctrl_dev *pctldev,
				      unsigned group)
{
	struct amd_gpio *gpio_dev = pinctrl_dev_get_drvdata(pctldev);

	return gpio_dev->groups[group].name;
}