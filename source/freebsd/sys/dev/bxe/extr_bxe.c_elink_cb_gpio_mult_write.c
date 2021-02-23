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
typedef  int /*<<< orphan*/  uint8_t ;
struct bxe_softc {int dummy; } ;

/* Variables and functions */
 int /*<<< orphan*/  bxe_gpio_mult_write (struct bxe_softc*,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 

uint8_t
elink_cb_gpio_mult_write(struct bxe_softc *sc,
                         uint8_t          pins,
                         uint8_t          mode) /* 0=low 1=high */
{
    return (bxe_gpio_mult_write(sc, pins, mode));
}