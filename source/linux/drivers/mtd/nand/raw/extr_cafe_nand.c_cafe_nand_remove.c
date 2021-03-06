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
struct pci_dev {int /*<<< orphan*/  irq; } ;
struct nand_chip {int dummy; } ;
struct mtd_info {int dummy; } ;
struct cafe_priv {int /*<<< orphan*/  dmaaddr; int /*<<< orphan*/  dmabuf; TYPE_1__* pdev; int /*<<< orphan*/  mmio; int /*<<< orphan*/  rs; } ;
struct TYPE_2__ {int /*<<< orphan*/  dev; } ;

/* Variables and functions */
 int /*<<< orphan*/  GLOBAL_IRQ_MASK ; 
 int cafe_readl (struct cafe_priv*,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  cafe_writel (struct cafe_priv*,int,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  dma_free_coherent (int /*<<< orphan*/ *,int,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  free_irq (int /*<<< orphan*/ ,struct mtd_info*) ; 
 int /*<<< orphan*/  free_rs (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  kfree (struct cafe_priv*) ; 
 struct nand_chip* mtd_to_nand (struct mtd_info*) ; 
 struct cafe_priv* nand_get_controller_data (struct nand_chip*) ; 
 int /*<<< orphan*/  nand_release (struct nand_chip*) ; 
 struct mtd_info* pci_get_drvdata (struct pci_dev*) ; 
 int /*<<< orphan*/  pci_iounmap (struct pci_dev*,int /*<<< orphan*/ ) ; 

__attribute__((used)) static void cafe_nand_remove(struct pci_dev *pdev)
{
	struct mtd_info *mtd = pci_get_drvdata(pdev);
	struct nand_chip *chip = mtd_to_nand(mtd);
	struct cafe_priv *cafe = nand_get_controller_data(chip);

	/* Disable NAND IRQ in global IRQ mask register */
	cafe_writel(cafe, ~1 & cafe_readl(cafe, GLOBAL_IRQ_MASK), GLOBAL_IRQ_MASK);
	free_irq(pdev->irq, mtd);
	nand_release(chip);
	free_rs(cafe->rs);
	pci_iounmap(pdev, cafe->mmio);
	dma_free_coherent(&cafe->pdev->dev, 2112, cafe->dmabuf, cafe->dmaaddr);
	kfree(cafe);
}