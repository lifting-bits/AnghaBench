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
struct gemtek_pci {int /*<<< orphan*/  lock; int /*<<< orphan*/  iobase; } ;

/* Variables and functions */
 int inb (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  mutex_lock (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  mutex_unlock (int /*<<< orphan*/ *) ; 

__attribute__((used)) static int gemtek_pci_getsignal(struct gemtek_pci *card)
{
	int sig;

	mutex_lock(&card->lock);
	sig = (inb(card->iobase) & 0x08) ? 0 : 1;
	mutex_unlock(&card->lock);
	return sig;
}