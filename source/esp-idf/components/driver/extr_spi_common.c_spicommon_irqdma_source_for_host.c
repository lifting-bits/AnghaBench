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
typedef  size_t spi_host_device_t ;
struct TYPE_2__ {int irq_dma; } ;

/* Variables and functions */
 TYPE_1__* spi_periph_signal ; 

int spicommon_irqdma_source_for_host(spi_host_device_t host)
{
    return spi_periph_signal[host].irq_dma;
}