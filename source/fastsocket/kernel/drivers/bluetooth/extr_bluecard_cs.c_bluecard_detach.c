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
struct pcmcia_device {int /*<<< orphan*/ * priv; } ;
typedef  int /*<<< orphan*/  bluecard_info_t ;

/* Variables and functions */
 int /*<<< orphan*/  bluecard_release (struct pcmcia_device*) ; 
 int /*<<< orphan*/  kfree (int /*<<< orphan*/ *) ; 

__attribute__((used)) static void bluecard_detach(struct pcmcia_device *link)
{
	bluecard_info_t *info = link->priv;

	bluecard_release(link);
	kfree(info);
}