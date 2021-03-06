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
typedef  int /*<<< orphan*/  u8 ;
struct sja1000_priv {scalar_t__ reg_base; struct f81601_pci_card* priv; } ;
struct f81601_pci_card {int /*<<< orphan*/  lock; } ;

/* Variables and functions */
 int /*<<< orphan*/  readb (scalar_t__) ; 
 int /*<<< orphan*/  spin_lock_irqsave (int /*<<< orphan*/ *,unsigned long) ; 
 int /*<<< orphan*/  spin_unlock_irqrestore (int /*<<< orphan*/ *,unsigned long) ; 
 int /*<<< orphan*/  writeb (int /*<<< orphan*/ ,scalar_t__) ; 

__attribute__((used)) static void f81601_pci_write_reg(const struct sja1000_priv *priv, int port,
				 u8 val)
{
	struct f81601_pci_card *card = priv->priv;
	unsigned long flags;

	spin_lock_irqsave(&card->lock, flags);
	writeb(val, priv->reg_base + port);
	readb(priv->reg_base);
	spin_unlock_irqrestore(&card->lock, flags);
}