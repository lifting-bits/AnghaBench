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
typedef  int uint32_t ;
struct uart_opal_softc {int vtermid; int /*<<< orphan*/  protocol; int /*<<< orphan*/  node; scalar_t__ outseqno; scalar_t__ inbuflen; } ;
typedef  int /*<<< orphan*/  reg ;
typedef  int /*<<< orphan*/  phandle_t ;
typedef  int /*<<< orphan*/  buf ;

/* Variables and functions */
 int ENXIO ; 
 int /*<<< orphan*/  OF_getencprop (int /*<<< orphan*/ ,char*,int*,int) ; 
 scalar_t__ OF_getprop (int /*<<< orphan*/ ,char*,char*,int) ; 
 int /*<<< orphan*/  OPAL_HVSI ; 
 int /*<<< orphan*/  OPAL_RAW ; 
 scalar_t__ strcmp (char*,char*) ; 

__attribute__((used)) static int
uart_opal_probe_node(struct uart_opal_softc *sc)
{
	phandle_t node = sc->node;
	uint32_t reg;
	char buf[64];

	sc->inbuflen = 0;
	sc->outseqno = 0;

	if (OF_getprop(node, "device_type", buf, sizeof(buf)) <= 0)
		return (ENXIO);
	if (strcmp(buf, "serial") != 0)
		return (ENXIO);

	reg = -1;
	OF_getencprop(node, "reg", &reg, sizeof(reg));
	if (reg == -1)
		return (ENXIO);
	sc->vtermid = reg;
	sc->node = node;

	if (OF_getprop(node, "compatible", buf, sizeof(buf)) <= 0)
		return (ENXIO);
	if (strcmp(buf, "ibm,opal-console-raw") == 0) {
		sc->protocol = OPAL_RAW;
		return (0);
	} else if (strcmp(buf, "ibm,opal-console-hvsi") == 0) {
		sc->protocol = OPAL_HVSI;
		return (0);
	}

	return (ENXIO);
}