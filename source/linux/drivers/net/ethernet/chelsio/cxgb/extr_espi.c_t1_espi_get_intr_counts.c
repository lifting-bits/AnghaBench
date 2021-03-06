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
struct espi_intr_counts {int dummy; } ;
struct peespi {struct espi_intr_counts const intr_cnt; } ;

/* Variables and functions */

const struct espi_intr_counts *t1_espi_get_intr_counts(struct peespi *espi)
{
	return &espi->intr_cnt;
}