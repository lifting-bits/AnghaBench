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
typedef  int uint8_t ;
typedef  int uint32_t ;
typedef  int uint16_t ;
struct usb_page_search {int length; void* buffer; } ;
struct musbotg_td {int channel; int max_frame_size; int remainder; int short_pkt; int offset; int /*<<< orphan*/  reg_max_packet; int /*<<< orphan*/  pc; } ;
struct musbotg_softc {void* sc_bounce_buf; int /*<<< orphan*/  sc_io_hdl; int /*<<< orphan*/  sc_io_tag; } ;

/* Variables and functions */
 int /*<<< orphan*/  DPRINTFN (int,char*,int) ; 
 int MUSB2_MASK_CSRL_TXINCOMP ; 
 int MUSB2_MASK_CSRL_TXPKTRDY ; 
 int MUSB2_MASK_CSRL_TXUNDERRUN ; 
 int MUSB2_READ_1 (struct musbotg_softc*,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  MUSB2_REG_EPFIFO (int) ; 
 int /*<<< orphan*/  MUSB2_REG_EPINDEX ; 
 int /*<<< orphan*/  MUSB2_REG_TXCSRL ; 
 int /*<<< orphan*/  MUSB2_REG_TXMAXP ; 
 int /*<<< orphan*/  MUSB2_WRITE_1 (struct musbotg_softc*,int /*<<< orphan*/ ,int) ; 
 int /*<<< orphan*/  MUSB2_WRITE_2 (struct musbotg_softc*,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 struct musbotg_softc* MUSBOTG_PC2SC (int /*<<< orphan*/ ) ; 
 int USB_P2U (void*) ; 
 int /*<<< orphan*/  bus_space_write_multi_1 (int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ,void*,int) ; 
 int /*<<< orphan*/  bus_space_write_multi_4 (int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ,void*,int) ; 
 int musbotg_channel_alloc (struct musbotg_softc*,struct musbotg_td*,int) ; 
 int /*<<< orphan*/  musbotg_channel_free (struct musbotg_softc*,struct musbotg_td*) ; 
 int /*<<< orphan*/  usbd_copy_out (int /*<<< orphan*/ ,int,void*,int) ; 
 int /*<<< orphan*/  usbd_get_page (int /*<<< orphan*/ ,int,struct usb_page_search*) ; 

__attribute__((used)) static uint8_t
musbotg_dev_data_tx(struct musbotg_td *td)
{
	struct usb_page_search buf_res;
	struct musbotg_softc *sc;
	uint16_t count;
	uint8_t csr;
	uint8_t to;

	to = 8;				/* don't loop forever! */

	/* get pointer to softc */
	sc = MUSBOTG_PC2SC(td->pc);

	if (td->channel == -1)
		td->channel = musbotg_channel_alloc(sc, td, 1);

	/* EP0 is busy, wait */
	if (td->channel == -1)
		return (1);

	/* select endpoint */
	MUSB2_WRITE_1(sc, MUSB2_REG_EPINDEX, td->channel);

repeat:

	/* read out FIFO status */
	csr = MUSB2_READ_1(sc, MUSB2_REG_TXCSRL);

	DPRINTFN(4, "csr=0x%02x\n", csr);

	if (csr & (MUSB2_MASK_CSRL_TXINCOMP |
	    MUSB2_MASK_CSRL_TXUNDERRUN)) {
		/* clear status bits */
		MUSB2_WRITE_1(sc, MUSB2_REG_TXCSRL, 0);
	}
	if (csr & MUSB2_MASK_CSRL_TXPKTRDY) {
		return (1);		/* not complete */
	}
	/* check for short packet */
	count = td->max_frame_size;
	if (td->remainder < count) {
		/* we have a short packet */
		td->short_pkt = 1;
		count = td->remainder;
	}
	while (count > 0) {
		uint32_t temp;

		usbd_get_page(td->pc, td->offset, &buf_res);

		/* get correct length */
		if (buf_res.length > count) {
			buf_res.length = count;
		}
		/* check for unaligned memory address */
		if (USB_P2U(buf_res.buffer) & 3) {

			usbd_copy_out(td->pc, td->offset,
			    sc->sc_bounce_buf, count);

			temp = count & ~3;

			if (temp) {
				/* transmit data 4 bytes at a time */
				bus_space_write_multi_4(sc->sc_io_tag,
				    sc->sc_io_hdl, MUSB2_REG_EPFIFO(td->channel),
				    sc->sc_bounce_buf, temp / 4);
			}
			temp = count & 3;
			if (temp) {
				/* receive data 1 byte at a time */
				bus_space_write_multi_1(sc->sc_io_tag, sc->sc_io_hdl,
				    MUSB2_REG_EPFIFO(td->channel),
				    ((void *)&sc->sc_bounce_buf[count / 4]), temp);
			}
			/* update offset and remainder */
			td->offset += count;
			td->remainder -= count;
			break;
		}
		/* check if we can optimise */
		if (buf_res.length >= 4) {

			/* transmit data 4 bytes at a time */
			bus_space_write_multi_4(sc->sc_io_tag, sc->sc_io_hdl,
			    MUSB2_REG_EPFIFO(td->channel), buf_res.buffer,
			    buf_res.length / 4);

			temp = buf_res.length & ~3;

			/* update counters */
			count -= temp;
			td->offset += temp;
			td->remainder -= temp;
			continue;
		}
		/* transmit data */
		bus_space_write_multi_1(sc->sc_io_tag, sc->sc_io_hdl,
		    MUSB2_REG_EPFIFO(td->channel), buf_res.buffer,
		    buf_res.length);

		/* update counters */
		count -= buf_res.length;
		td->offset += buf_res.length;
		td->remainder -= buf_res.length;
	}

	/* Max packet size */
	MUSB2_WRITE_2(sc, MUSB2_REG_TXMAXP, td->reg_max_packet);

	/* write command */
	MUSB2_WRITE_1(sc, MUSB2_REG_TXCSRL,
	    MUSB2_MASK_CSRL_TXPKTRDY);

	/* check remainder */
	if (td->remainder == 0) {
		if (td->short_pkt) {
			musbotg_channel_free(sc, td);
			return (0);	/* complete */
		}
		/* else we need to transmit a short packet */
	}
	if (--to) {
		goto repeat;
	}
	return (1);			/* not complete */
}