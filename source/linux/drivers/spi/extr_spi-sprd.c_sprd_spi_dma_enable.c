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
typedef  int /*<<< orphan*/  u32 ;
struct sprd_spi {scalar_t__ base; } ;

/* Variables and functions */
 scalar_t__ SPRD_SPI_CTL2 ; 
 int /*<<< orphan*/  SPRD_SPI_DMA_EN ; 
 int /*<<< orphan*/  readl_relaxed (scalar_t__) ; 
 int /*<<< orphan*/  writel_relaxed (int /*<<< orphan*/ ,scalar_t__) ; 

__attribute__((used)) static void sprd_spi_dma_enable(struct sprd_spi *ss, bool enable)
{
	u32 val = readl_relaxed(ss->base + SPRD_SPI_CTL2);

	if (enable)
		val |= SPRD_SPI_DMA_EN;
	else
		val &= ~SPRD_SPI_DMA_EN;

	writel_relaxed(val, ss->base + SPRD_SPI_CTL2);
}