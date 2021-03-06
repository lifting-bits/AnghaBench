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
typedef  unsigned int u32 ;
struct sun6i_spi {unsigned int len; int fifo_depth; int /*<<< orphan*/  done; scalar_t__ tx_buf; int /*<<< orphan*/  mclk; scalar_t__ rx_buf; } ;
struct spi_transfer {unsigned int len; int speed_hz; scalar_t__ rx_buf; scalar_t__ tx_buf; } ;
struct spi_master {int /*<<< orphan*/  dev; } ;
struct spi_device {int mode; int /*<<< orphan*/  dev; } ;

/* Variables and functions */
 int EINVAL ; 
 int ETIMEDOUT ; 
 int SPI_CPHA ; 
 int SPI_CPOL ; 
 int SPI_LSB_FIRST ; 
 unsigned int SUN6I_BURST_CNT (unsigned int) ; 
 int /*<<< orphan*/  SUN6I_BURST_CNT_REG ; 
 int /*<<< orphan*/  SUN6I_BURST_CTL_CNT_REG ; 
 unsigned int SUN6I_BURST_CTL_CNT_STC (unsigned int) ; 
 unsigned int SUN6I_CLK_CTL_CDR1 (unsigned int) ; 
 unsigned int SUN6I_CLK_CTL_CDR2 (unsigned int) ; 
 int SUN6I_CLK_CTL_CDR2_MASK ; 
 unsigned int SUN6I_CLK_CTL_DRS ; 
 int /*<<< orphan*/  SUN6I_CLK_CTL_REG ; 
 int /*<<< orphan*/  SUN6I_FIFO_CTL_REG ; 
 unsigned int SUN6I_FIFO_CTL_RF_RDY_TRIG_LEVEL_BITS ; 
 unsigned int SUN6I_FIFO_CTL_RF_RST ; 
 unsigned int SUN6I_FIFO_CTL_TF_ERQ_TRIG_LEVEL_BITS ; 
 unsigned int SUN6I_FIFO_CTL_TF_RST ; 
 int /*<<< orphan*/  SUN6I_INT_CTL_REG ; 
 unsigned int SUN6I_INT_CTL_RF_RDY ; 
 unsigned int SUN6I_INT_CTL_TC ; 
 unsigned int SUN6I_INT_CTL_TF_ERQ ; 
 int /*<<< orphan*/  SUN6I_INT_STA_REG ; 
 unsigned int SUN6I_MAX_XFER_SIZE ; 
 unsigned int SUN6I_TFR_CTL_CPHA ; 
 unsigned int SUN6I_TFR_CTL_CPOL ; 
 unsigned int SUN6I_TFR_CTL_CS_MANUAL ; 
 unsigned int SUN6I_TFR_CTL_DHB ; 
 unsigned int SUN6I_TFR_CTL_FBS ; 
 int /*<<< orphan*/  SUN6I_TFR_CTL_REG ; 
 unsigned int SUN6I_TFR_CTL_XCH ; 
 unsigned int SUN6I_XMIT_CNT (unsigned int) ; 
 int /*<<< orphan*/  SUN6I_XMIT_CNT_REG ; 
 unsigned int clk_get_rate (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  clk_set_rate (int /*<<< orphan*/ ,int) ; 
 int /*<<< orphan*/  dev_name (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  dev_warn (int /*<<< orphan*/ *,char*,int /*<<< orphan*/ ,int,int,int /*<<< orphan*/ ,unsigned int) ; 
 unsigned int ilog2 (unsigned int) ; 
 unsigned int jiffies ; 
 int /*<<< orphan*/  jiffies_to_msecs (unsigned int) ; 
 unsigned int max (int,unsigned int) ; 
 int /*<<< orphan*/  msecs_to_jiffies (unsigned int) ; 
 int /*<<< orphan*/  reinit_completion (int /*<<< orphan*/ *) ; 
 struct sun6i_spi* spi_master_get_devdata (struct spi_master*) ; 
 int /*<<< orphan*/  sun6i_spi_enable_interrupt (struct sun6i_spi*,unsigned int) ; 
 int /*<<< orphan*/  sun6i_spi_fill_fifo (struct sun6i_spi*,int) ; 
 unsigned int sun6i_spi_read (struct sun6i_spi*,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  sun6i_spi_write (struct sun6i_spi*,int /*<<< orphan*/ ,unsigned int) ; 
 unsigned int wait_for_completion_timeout (int /*<<< orphan*/ *,int /*<<< orphan*/ ) ; 

__attribute__((used)) static int sun6i_spi_transfer_one(struct spi_master *master,
				  struct spi_device *spi,
				  struct spi_transfer *tfr)
{
	struct sun6i_spi *sspi = spi_master_get_devdata(master);
	unsigned int mclk_rate, div, timeout;
	unsigned int start, end, tx_time;
	unsigned int trig_level;
	unsigned int tx_len = 0;
	int ret = 0;
	u32 reg;

	if (tfr->len > SUN6I_MAX_XFER_SIZE)
		return -EINVAL;

	reinit_completion(&sspi->done);
	sspi->tx_buf = tfr->tx_buf;
	sspi->rx_buf = tfr->rx_buf;
	sspi->len = tfr->len;

	/* Clear pending interrupts */
	sun6i_spi_write(sspi, SUN6I_INT_STA_REG, ~0);

	/* Reset FIFO */
	sun6i_spi_write(sspi, SUN6I_FIFO_CTL_REG,
			SUN6I_FIFO_CTL_RF_RST | SUN6I_FIFO_CTL_TF_RST);

	/*
	 * Setup FIFO interrupt trigger level
	 * Here we choose 3/4 of the full fifo depth, as it's the hardcoded
	 * value used in old generation of Allwinner SPI controller.
	 * (See spi-sun4i.c)
	 */
	trig_level = sspi->fifo_depth / 4 * 3;
	sun6i_spi_write(sspi, SUN6I_FIFO_CTL_REG,
			(trig_level << SUN6I_FIFO_CTL_RF_RDY_TRIG_LEVEL_BITS) |
			(trig_level << SUN6I_FIFO_CTL_TF_ERQ_TRIG_LEVEL_BITS));

	/*
	 * Setup the transfer control register: Chip Select,
	 * polarities, etc.
	 */
	reg = sun6i_spi_read(sspi, SUN6I_TFR_CTL_REG);

	if (spi->mode & SPI_CPOL)
		reg |= SUN6I_TFR_CTL_CPOL;
	else
		reg &= ~SUN6I_TFR_CTL_CPOL;

	if (spi->mode & SPI_CPHA)
		reg |= SUN6I_TFR_CTL_CPHA;
	else
		reg &= ~SUN6I_TFR_CTL_CPHA;

	if (spi->mode & SPI_LSB_FIRST)
		reg |= SUN6I_TFR_CTL_FBS;
	else
		reg &= ~SUN6I_TFR_CTL_FBS;

	/*
	 * If it's a TX only transfer, we don't want to fill the RX
	 * FIFO with bogus data
	 */
	if (sspi->rx_buf)
		reg &= ~SUN6I_TFR_CTL_DHB;
	else
		reg |= SUN6I_TFR_CTL_DHB;

	/* We want to control the chip select manually */
	reg |= SUN6I_TFR_CTL_CS_MANUAL;

	sun6i_spi_write(sspi, SUN6I_TFR_CTL_REG, reg);

	/* Ensure that we have a parent clock fast enough */
	mclk_rate = clk_get_rate(sspi->mclk);
	if (mclk_rate < (2 * tfr->speed_hz)) {
		clk_set_rate(sspi->mclk, 2 * tfr->speed_hz);
		mclk_rate = clk_get_rate(sspi->mclk);
	}

	/*
	 * Setup clock divider.
	 *
	 * We have two choices there. Either we can use the clock
	 * divide rate 1, which is calculated thanks to this formula:
	 * SPI_CLK = MOD_CLK / (2 ^ cdr)
	 * Or we can use CDR2, which is calculated with the formula:
	 * SPI_CLK = MOD_CLK / (2 * (cdr + 1))
	 * Wether we use the former or the latter is set through the
	 * DRS bit.
	 *
	 * First try CDR2, and if we can't reach the expected
	 * frequency, fall back to CDR1.
	 */
	div = mclk_rate / (2 * tfr->speed_hz);
	if (div <= (SUN6I_CLK_CTL_CDR2_MASK + 1)) {
		if (div > 0)
			div--;

		reg = SUN6I_CLK_CTL_CDR2(div) | SUN6I_CLK_CTL_DRS;
	} else {
		div = ilog2(mclk_rate) - ilog2(tfr->speed_hz);
		reg = SUN6I_CLK_CTL_CDR1(div);
	}

	sun6i_spi_write(sspi, SUN6I_CLK_CTL_REG, reg);

	/* Setup the transfer now... */
	if (sspi->tx_buf)
		tx_len = tfr->len;

	/* Setup the counters */
	sun6i_spi_write(sspi, SUN6I_BURST_CNT_REG, SUN6I_BURST_CNT(tfr->len));
	sun6i_spi_write(sspi, SUN6I_XMIT_CNT_REG, SUN6I_XMIT_CNT(tx_len));
	sun6i_spi_write(sspi, SUN6I_BURST_CTL_CNT_REG,
			SUN6I_BURST_CTL_CNT_STC(tx_len));

	/* Fill the TX FIFO */
	sun6i_spi_fill_fifo(sspi, sspi->fifo_depth);

	/* Enable the interrupts */
	sun6i_spi_write(sspi, SUN6I_INT_CTL_REG, SUN6I_INT_CTL_TC);
	sun6i_spi_enable_interrupt(sspi, SUN6I_INT_CTL_TC |
					 SUN6I_INT_CTL_RF_RDY);
	if (tx_len > sspi->fifo_depth)
		sun6i_spi_enable_interrupt(sspi, SUN6I_INT_CTL_TF_ERQ);

	/* Start the transfer */
	reg = sun6i_spi_read(sspi, SUN6I_TFR_CTL_REG);
	sun6i_spi_write(sspi, SUN6I_TFR_CTL_REG, reg | SUN6I_TFR_CTL_XCH);

	tx_time = max(tfr->len * 8 * 2 / (tfr->speed_hz / 1000), 100U);
	start = jiffies;
	timeout = wait_for_completion_timeout(&sspi->done,
					      msecs_to_jiffies(tx_time));
	end = jiffies;
	if (!timeout) {
		dev_warn(&master->dev,
			 "%s: timeout transferring %u bytes@%iHz for %i(%i)ms",
			 dev_name(&spi->dev), tfr->len, tfr->speed_hz,
			 jiffies_to_msecs(end - start), tx_time);
		ret = -ETIMEDOUT;
		goto out;
	}

out:
	sun6i_spi_write(sspi, SUN6I_INT_CTL_REG, 0);

	return ret;
}