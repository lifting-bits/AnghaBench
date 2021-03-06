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
typedef  int u8 ;
typedef  int u32 ;
struct xenon_priv {int sdhc_id; } ;
struct sdhci_pltfm_host {int dummy; } ;
struct sdhci_host {int dummy; } ;
struct mmc_host {int dummy; } ;

/* Variables and functions */
 int XENON_SLOT_TYPE_SDIO_SHIFT ; 
 int /*<<< orphan*/  XENON_SYS_CFG_INFO ; 
 struct sdhci_host* mmc_priv (struct mmc_host*) ; 
 int /*<<< orphan*/  sdhci_enable_sdio_irq (struct mmc_host*,int) ; 
 struct xenon_priv* sdhci_pltfm_priv (struct sdhci_pltfm_host*) ; 
 struct sdhci_pltfm_host* sdhci_priv (struct sdhci_host*) ; 
 int sdhci_readl (struct sdhci_host*,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  sdhci_writel (struct sdhci_host*,int,int /*<<< orphan*/ ) ; 

__attribute__((used)) static void xenon_enable_sdio_irq(struct mmc_host *mmc, int enable)
{
	struct sdhci_host *host = mmc_priv(mmc);
	struct sdhci_pltfm_host *pltfm_host = sdhci_priv(host);
	struct xenon_priv *priv = sdhci_pltfm_priv(pltfm_host);
	u32 reg;
	u8 sdhc_id = priv->sdhc_id;

	sdhci_enable_sdio_irq(mmc, enable);

	if (enable) {
		/*
		 * Set SDIO Card Inserted indication
		 * to enable detecting SDIO async irq.
		 */
		reg = sdhci_readl(host, XENON_SYS_CFG_INFO);
		reg |= (1 << (sdhc_id + XENON_SLOT_TYPE_SDIO_SHIFT));
		sdhci_writel(host, reg, XENON_SYS_CFG_INFO);
	} else {
		/* Clear SDIO Card Inserted indication */
		reg = sdhci_readl(host, XENON_SYS_CFG_INFO);
		reg &= ~(1 << (sdhc_id + XENON_SLOT_TYPE_SDIO_SHIFT));
		sdhci_writel(host, reg, XENON_SYS_CFG_INFO);
	}
}