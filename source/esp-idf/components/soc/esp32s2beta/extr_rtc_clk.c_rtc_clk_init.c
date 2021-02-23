#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_3__   TYPE_1__ ;

/* Type definitions */
typedef  int uint32_t ;
typedef  int rtc_xtal_freq_t ;
typedef  int /*<<< orphan*/  rtc_cpu_freq_t ;
struct TYPE_3__ {int xtal_freq; scalar_t__ slow_freq; scalar_t__ fast_freq; int /*<<< orphan*/  cpu_freq; int /*<<< orphan*/  clk_8m_clk_div; int /*<<< orphan*/  clk_rtc_clk_div; int /*<<< orphan*/  clk_8m_dfreq; int /*<<< orphan*/  slow_clk_dcap; } ;
typedef  TYPE_1__ rtc_clk_config_t ;

/* Variables and functions */
 int /*<<< orphan*/  ANA_CONFIG_M ; 
 int /*<<< orphan*/  ANA_CONFIG_REG ; 
 int /*<<< orphan*/  ANA_CONFIG_S ; 
 int /*<<< orphan*/  CLEAR_PERI_REG_MASK (int /*<<< orphan*/ ,int) ; 
 int I2C_APLL_M ; 
 int I2C_BBPLL_M ; 
 int MHZ ; 
 int /*<<< orphan*/  READ_PERI_REG (int /*<<< orphan*/ ) ; 
 scalar_t__ REG_GET_FIELD (int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  REG_SET_FIELD (int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  RTC_CNTL_CK8M_DFREQ ; 
 int /*<<< orphan*/  RTC_CNTL_CLK_CONF_REG ; 
 int /*<<< orphan*/  RTC_CNTL_REG ; 
 int /*<<< orphan*/  RTC_CNTL_SCK_DCAP ; 
 int /*<<< orphan*/  RTC_CPU_FREQ_XTAL ; 
 scalar_t__ RTC_FAST_FREQ_8M ; 
 scalar_t__ RTC_SLOW_FREQ_32K_XTAL ; 
 scalar_t__ RTC_SLOW_FREQ_8MD256 ; 
 int RTC_XTAL_FREQ_26M ; 
 int RTC_XTAL_FREQ_AUTO ; 
 int /*<<< orphan*/  RTC_XTAL_FREQ_REG ; 
 int /*<<< orphan*/  SET_PERI_REG_BITS (int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  SOC_LOGW (int /*<<< orphan*/ ,char*,...) ; 
 int /*<<< orphan*/  SYSCON_SOC_CLK_SEL ; 
 scalar_t__ SYSCON_SOC_CLK_SEL_PLL ; 
 int /*<<< orphan*/  SYSCON_SYSCLK_CONF_REG ; 
 int /*<<< orphan*/  TAG ; 
 int XTHAL_GET_CCOUNT () ; 
 int /*<<< orphan*/  XTHAL_SET_CCOUNT (int) ; 
 scalar_t__ clk_val_is_valid (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  rtc_clk_32k_enable (int) ; 
 int /*<<< orphan*/  rtc_clk_8m_divider_set (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  rtc_clk_8m_enable (int,int) ; 
 int /*<<< orphan*/  rtc_clk_apb_freq_update (int) ; 
 int /*<<< orphan*/  rtc_clk_cpu_freq_get () ; 
 int /*<<< orphan*/  rtc_clk_cpu_freq_set (int /*<<< orphan*/ ) ; 
 int rtc_clk_cpu_freq_value (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  rtc_clk_divider_set (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  rtc_clk_fast_freq_set (scalar_t__) ; 
 int /*<<< orphan*/  rtc_clk_slow_freq_set (scalar_t__) ; 
 int rtc_clk_xtal_freq_estimate () ; 
 int rtc_clk_xtal_freq_get () ; 
 int /*<<< orphan*/  rtc_clk_xtal_freq_update (int) ; 
 int /*<<< orphan*/  uart_tx_wait_idle (int /*<<< orphan*/ ) ; 

void rtc_clk_init(rtc_clk_config_t cfg)
{
    rtc_cpu_freq_t cpu_source_before = rtc_clk_cpu_freq_get();
    /* If we get a TG WDT system reset while running at 240MHz,
     * DPORT_CPUPERIOD_SEL register will be reset to 0 resulting in 120MHz
     * APB and CPU frequencies after reset. This will cause issues with XTAL
     * frequency estimation, so we switch to XTAL frequency first.
     *
     * Ideally we would only do this if SYSCON_SOC_CLK_SEL == PLL and
     * PLL is configured for 480M, but it takes less time to switch to 40M and
     * run the following code than querying the PLL does.
     */
    if (REG_GET_FIELD(SYSCON_SYSCLK_CONF_REG, SYSCON_SOC_CLK_SEL) == SYSCON_SOC_CLK_SEL_PLL) {
        rtc_clk_cpu_freq_set(RTC_CPU_FREQ_XTAL);
    }

    /* Set tuning parameters for 8M and 150k clocks.
     * Note: this doesn't attempt to set the clocks to precise frequencies.
     * Instead, we calibrate these clocks against XTAL frequency later, when necessary.
     * - SCK_DCAP value controls tuning of 150k clock.
     *   The higher the value of DCAP is, the lower is the frequency.
     * - CK8M_DFREQ value controls tuning of 8M clock.
     *   CLK_8M_DFREQ constant gives the best temperature characteristics.
     */
    REG_SET_FIELD(RTC_CNTL_REG, RTC_CNTL_SCK_DCAP, cfg.slow_clk_dcap);
    REG_SET_FIELD(RTC_CNTL_CLK_CONF_REG, RTC_CNTL_CK8M_DFREQ, cfg.clk_8m_dfreq);

    /* Configure 150k clock division */
    rtc_clk_divider_set(cfg.clk_rtc_clk_div);
    /* Configure 8M clock division */
    rtc_clk_8m_divider_set(cfg.clk_8m_clk_div);

    /* Enable the internal bus used to configure PLLs */
    SET_PERI_REG_BITS(ANA_CONFIG_REG, ANA_CONFIG_M, ANA_CONFIG_M, ANA_CONFIG_S);
    CLEAR_PERI_REG_MASK(ANA_CONFIG_REG, I2C_APLL_M | I2C_BBPLL_M);

    /* Estimate XTAL frequency */
    rtc_xtal_freq_t xtal_freq = cfg.xtal_freq;
    if (xtal_freq == RTC_XTAL_FREQ_AUTO) {
        if (clk_val_is_valid(READ_PERI_REG(RTC_XTAL_FREQ_REG))) {
            /* XTAL frequency has already been set, use existing value */
            xtal_freq = rtc_clk_xtal_freq_get();
        } else {
            /* Not set yet, estimate XTAL frequency based on RTC_FAST_CLK */
            xtal_freq = rtc_clk_xtal_freq_estimate();
            if (xtal_freq == RTC_XTAL_FREQ_AUTO) {
                SOC_LOGW(TAG, "Can't estimate XTAL frequency, assuming 26MHz");
                xtal_freq = RTC_XTAL_FREQ_26M;
            }
        }
    } else if (!clk_val_is_valid(READ_PERI_REG(RTC_XTAL_FREQ_REG))) {
        /* Exact frequency was set in sdkconfig, but still warn if autodetected
         * frequency is different. If autodetection failed, worst case we get a
         * bit of garbage output.
         */
        rtc_xtal_freq_t est_xtal_freq = rtc_clk_xtal_freq_estimate();
        if (est_xtal_freq != xtal_freq) {
            SOC_LOGW(TAG, "Possibly invalid CONFIG_ESP32S2_XTAL_FREQ setting (%dMHz). Detected %d MHz.",
                    xtal_freq, est_xtal_freq);
        }
    }
    uart_tx_wait_idle(0);
    rtc_clk_xtal_freq_update(xtal_freq);
    rtc_clk_apb_freq_update(xtal_freq * MHZ);
    /* Set CPU frequency */
    rtc_clk_cpu_freq_set(cfg.cpu_freq);

    /* Re-calculate the ccount to make time calculation correct. */
    uint32_t freq_before = rtc_clk_cpu_freq_value(cpu_source_before) / MHZ;
    uint32_t freq_after = rtc_clk_cpu_freq_value(cfg.cpu_freq) / MHZ;
    XTHAL_SET_CCOUNT( XTHAL_GET_CCOUNT() * freq_after / freq_before );

    /* Slow & fast clocks setup */
    if (cfg.slow_freq == RTC_SLOW_FREQ_32K_XTAL) {
        rtc_clk_32k_enable(true);
    }
    if (cfg.fast_freq == RTC_FAST_FREQ_8M) {
        bool need_8md256 = cfg.slow_freq == RTC_SLOW_FREQ_8MD256;
        rtc_clk_8m_enable(true, need_8md256);
    }
    rtc_clk_fast_freq_set(cfg.fast_freq);
    rtc_clk_slow_freq_set(cfg.slow_freq);
}