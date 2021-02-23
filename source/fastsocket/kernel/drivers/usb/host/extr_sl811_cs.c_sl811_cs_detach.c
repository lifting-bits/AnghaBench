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
struct pcmcia_device {int /*<<< orphan*/  priv; } ;

/* Variables and functions */
 int /*<<< orphan*/  DBG (int /*<<< orphan*/ ,char*,struct pcmcia_device*) ; 
 int /*<<< orphan*/  kfree (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  sl811_cs_release (struct pcmcia_device*) ; 

__attribute__((used)) static void sl811_cs_detach(struct pcmcia_device *link)
{
	DBG(0, "sl811_cs_detach(0x%p)\n", link);

	sl811_cs_release(link);

	/* This points to the parent local_info_t struct */
	kfree(link->priv);
}