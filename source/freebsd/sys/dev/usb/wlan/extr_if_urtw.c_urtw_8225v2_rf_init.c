#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_5__   TYPE_1__ ;

/* Type definitions */
typedef  scalar_t__ usb_error_t ;
typedef  int uint8_t ;
typedef  int uint32_t ;
typedef  int /*<<< orphan*/  uint16_t ;
struct urtw_softc {int /*<<< orphan*/  sc_mtx; int /*<<< orphan*/  sc_dev; } ;
struct TYPE_5__ {int reg; int val; } ;

/* Variables and functions */
 int URTW_8225_ADDR_0_DATA_MAGIC1 ; 
 int URTW_8225_ADDR_0_DATA_MAGIC2 ; 
 int URTW_8225_ADDR_0_DATA_MAGIC6 ; 
 int URTW_8225_ADDR_0_MAGIC ; 
 int URTW_8225_ADDR_1_MAGIC ; 
 int URTW_8225_ADDR_2_DATA_MAGIC1 ; 
 int URTW_8225_ADDR_2_DATA_MAGIC2 ; 
 int URTW_8225_ADDR_2_MAGIC ; 
 int URTW_8225_ADDR_3_DATA_MAGIC1 ; 
 int URTW_8225_ADDR_3_MAGIC ; 
 int URTW_8225_ADDR_5_DATA_MAGIC1 ; 
 int URTW_8225_ADDR_5_MAGIC ; 
 int URTW_8225_ADDR_6_DATA_MAGIC1 ; 
 int URTW_8225_ADDR_6_DATA_MAGIC2 ; 
 int /*<<< orphan*/  URTW_8225_ADDR_6_MAGIC ; 
 int /*<<< orphan*/  URTW_8225_ANAPARAM_ON ; 
 int /*<<< orphan*/  URTW_BRSR ; 
 int /*<<< orphan*/  URTW_CONFIG3 ; 
 int /*<<< orphan*/  URTW_EPROM_CMD_CONFIG ; 
 int /*<<< orphan*/  URTW_EPROM_CMD_NORMAL ; 
 int /*<<< orphan*/  URTW_HSSI_PARA ; 
 int /*<<< orphan*/  URTW_RF_PARA ; 
 int /*<<< orphan*/  URTW_RF_TIMING ; 
 int /*<<< orphan*/  URTW_TESTR ; 
 int /*<<< orphan*/  device_printf (int /*<<< orphan*/ ,char*,...) ; 
 unsigned int nitems (TYPE_1__*) ; 
 scalar_t__ urtw_8180_set_anaparam (struct urtw_softc*,int /*<<< orphan*/ ) ; 
 scalar_t__ urtw_8185_rf_pins_enable (struct urtw_softc*) ; 
 scalar_t__ urtw_8185_tx_antenna (struct urtw_softc*,int) ; 
 int /*<<< orphan*/  urtw_8187_write_phy_cck (struct urtw_softc*,int,int) ; 
 int /*<<< orphan*/  urtw_8187_write_phy_ofdm (struct urtw_softc*,int,int) ; 
 int* urtw_8225_agc ; 
 scalar_t__ urtw_8225_read (struct urtw_softc*,int /*<<< orphan*/ ,int*) ; 
 scalar_t__ urtw_8225_rf_set_chan (struct urtw_softc*,int) ; 
 scalar_t__ urtw_8225_usb_init (struct urtw_softc*) ; 
 int /*<<< orphan*/  urtw_8225_write (struct urtw_softc*,int,int) ; 
 TYPE_1__* urtw_8225v2_rf_part1 ; 
 TYPE_1__* urtw_8225v2_rf_part2 ; 
 TYPE_1__* urtw_8225v2_rf_part3 ; 
 int* urtw_8225v2_rxgain ; 
 scalar_t__ urtw_8225v2_set_txpwrlvl (struct urtw_softc*,int) ; 
 scalar_t__ urtw_8225v2_setgain (struct urtw_softc*,int) ; 
 int /*<<< orphan*/  urtw_read16_m (struct urtw_softc*,int /*<<< orphan*/ ,int /*<<< orphan*/ *) ; 
 scalar_t__ urtw_set_mode (struct urtw_softc*,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  urtw_write16_m (struct urtw_softc*,int /*<<< orphan*/ ,int) ; 
 int /*<<< orphan*/  urtw_write32_m (struct urtw_softc*,int /*<<< orphan*/ ,int) ; 
 int /*<<< orphan*/  urtw_write8_m (struct urtw_softc*,int /*<<< orphan*/ ,int) ; 
 int /*<<< orphan*/  usb_pause_mtx (int /*<<< orphan*/ *,int) ; 

__attribute__((used)) static usb_error_t
urtw_8225v2_rf_init(struct urtw_softc *sc)
{
	unsigned int i;
	uint16_t data;
	uint32_t data32;
	usb_error_t error;

	error = urtw_8180_set_anaparam(sc, URTW_8225_ANAPARAM_ON);
	if (error)
		goto fail;

	error = urtw_8225_usb_init(sc);
	if (error)
		goto fail;

	urtw_write32_m(sc, URTW_RF_TIMING, 0x000a8008);
	urtw_read16_m(sc, URTW_BRSR, &data);		/* XXX ??? */
	urtw_write16_m(sc, URTW_BRSR, 0xffff);
	urtw_write32_m(sc, URTW_RF_PARA, 0x100044);

	error = urtw_set_mode(sc, URTW_EPROM_CMD_CONFIG);
	if (error)
		goto fail;
	urtw_write8_m(sc, URTW_CONFIG3, 0x44);
	error = urtw_set_mode(sc, URTW_EPROM_CMD_NORMAL);
	if (error)
		goto fail;

	error = urtw_8185_rf_pins_enable(sc);
	if (error)
		goto fail;

	usb_pause_mtx(&sc->sc_mtx, 500);

	for (i = 0; i < nitems(urtw_8225v2_rf_part1); i++) {
		urtw_8225_write(sc, urtw_8225v2_rf_part1[i].reg,
		    urtw_8225v2_rf_part1[i].val);
	}
	usb_pause_mtx(&sc->sc_mtx, 50);

	urtw_8225_write(sc,
	    URTW_8225_ADDR_0_MAGIC, URTW_8225_ADDR_0_DATA_MAGIC1);

	for (i = 0; i < 95; i++) {
		urtw_8225_write(sc, URTW_8225_ADDR_1_MAGIC, (uint8_t)(i + 1));
		urtw_8225_write(sc, URTW_8225_ADDR_2_MAGIC,
		    urtw_8225v2_rxgain[i]);
	}

	urtw_8225_write(sc,
	    URTW_8225_ADDR_3_MAGIC, URTW_8225_ADDR_3_DATA_MAGIC1);
	urtw_8225_write(sc,
	    URTW_8225_ADDR_5_MAGIC, URTW_8225_ADDR_5_DATA_MAGIC1);
	urtw_8225_write(sc,
	    URTW_8225_ADDR_0_MAGIC, URTW_8225_ADDR_0_DATA_MAGIC2);
	urtw_8225_write(sc,
	    URTW_8225_ADDR_2_MAGIC, URTW_8225_ADDR_2_DATA_MAGIC1);
	usb_pause_mtx(&sc->sc_mtx, 100);
	urtw_8225_write(sc,
	    URTW_8225_ADDR_2_MAGIC, URTW_8225_ADDR_2_DATA_MAGIC2);
	usb_pause_mtx(&sc->sc_mtx, 100);

	error = urtw_8225_read(sc, URTW_8225_ADDR_6_MAGIC, &data32);
	if (error != 0)
		goto fail;
	if (data32 != URTW_8225_ADDR_6_DATA_MAGIC1)
		device_printf(sc->sc_dev, "expect 0xe6!! (0x%x)\n", data32);
	if (!(data32 & URTW_8225_ADDR_6_DATA_MAGIC2)) {
		urtw_8225_write(sc,
		    URTW_8225_ADDR_2_MAGIC, URTW_8225_ADDR_2_DATA_MAGIC1);
		usb_pause_mtx(&sc->sc_mtx, 100);
		urtw_8225_write(sc,
		    URTW_8225_ADDR_2_MAGIC, URTW_8225_ADDR_2_DATA_MAGIC2);
		usb_pause_mtx(&sc->sc_mtx, 50);
		error = urtw_8225_read(sc, URTW_8225_ADDR_6_MAGIC, &data32);
		if (error != 0)
			goto fail;
		if (!(data32 & URTW_8225_ADDR_6_DATA_MAGIC2))
			device_printf(sc->sc_dev, "RF calibration failed\n");
	}
	usb_pause_mtx(&sc->sc_mtx, 100);

	urtw_8225_write(sc,
	    URTW_8225_ADDR_0_MAGIC, URTW_8225_ADDR_0_DATA_MAGIC6);
	for (i = 0; i < 128; i++) {
		urtw_8187_write_phy_ofdm(sc, 0xb, urtw_8225_agc[i]);
		urtw_8187_write_phy_ofdm(sc, 0xa, (uint8_t)i + 0x80);
	}

	for (i = 0; i < nitems(urtw_8225v2_rf_part2); i++) {
		urtw_8187_write_phy_ofdm(sc, urtw_8225v2_rf_part2[i].reg,
		    urtw_8225v2_rf_part2[i].val);
	}

	error = urtw_8225v2_setgain(sc, 4);
	if (error)
		goto fail;

	for (i = 0; i < nitems(urtw_8225v2_rf_part3); i++) {
		urtw_8187_write_phy_cck(sc, urtw_8225v2_rf_part3[i].reg,
		    urtw_8225v2_rf_part3[i].val);
	}

	urtw_write8_m(sc, URTW_TESTR, 0x0d);

	error = urtw_8225v2_set_txpwrlvl(sc, 1);
	if (error)
		goto fail;

	urtw_8187_write_phy_cck(sc, 0x10, 0x9b);
	urtw_8187_write_phy_ofdm(sc, 0x26, 0x90);

	/* TX ant A, 0x0 for B */
	error = urtw_8185_tx_antenna(sc, 0x3);
	if (error)
		goto fail;
	urtw_write32_m(sc, URTW_HSSI_PARA, 0x3dc00002);

	error = urtw_8225_rf_set_chan(sc, 1);
fail:
	return (error);
}