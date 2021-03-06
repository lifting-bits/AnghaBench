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
struct ifnet {scalar_t__ if_softc; } ;
struct TYPE_2__ {int port; } ;
typedef  TYPE_1__ cvm_oct_private_t ;

/* Variables and functions */
 int /*<<< orphan*/  CVMX_SPI_MODE_DUPLEX ; 
 int /*<<< orphan*/  cvm_oct_spi_enable_error_reporting (int) ; 
 int /*<<< orphan*/  cvmx_spi4000_check_speed (int,int) ; 
 scalar_t__ cvmx_spi_restart_interface (int,int /*<<< orphan*/ ,int) ; 
 scalar_t__* need_retrain ; 

__attribute__((used)) static void cvm_oct_spi_poll(struct ifnet *ifp)
{
	static int spi4000_port;
	cvm_oct_private_t *priv = (cvm_oct_private_t *)ifp->if_softc;
	int interface;

	for (interface = 0; interface < 2; interface++) {

		if ((priv->port == interface*16) && need_retrain[interface]) {

			if (cvmx_spi_restart_interface(interface, CVMX_SPI_MODE_DUPLEX, 10) == 0) {
				need_retrain[interface] = 0;
				cvm_oct_spi_enable_error_reporting(interface);
			}
		}

		/* The SPI4000 TWSI interface is very slow. In order not to
		   bring the system to a crawl, we only poll a single port
		   every second. This means negotiation speed changes
		   take up to 10 seconds, but at least we don't waste
		   absurd amounts of time waiting for TWSI */
		if (priv->port == spi4000_port) {
			/* This function does nothing if it is called on an
			   interface without a SPI4000 */
			cvmx_spi4000_check_speed(interface, priv->port);
			/* Normal ordering increments. By decrementing
			   we only match once per iteration */
			spi4000_port--;
			if (spi4000_port < 0)
				spi4000_port = 10;
		}
	}
}