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
struct rtc8583_softc {int /*<<< orphan*/  dev; } ;

/* Variables and functions */
 int /*<<< orphan*/  IIC_WAIT ; 
 int iicdev_readfrom (int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ *,int,int /*<<< orphan*/ ) ; 

__attribute__((used)) static inline int
rtc8583_read1(struct rtc8583_softc *sc, uint8_t reg, uint8_t *data) 
{

	return (iicdev_readfrom(sc->dev, reg, data, 1, IIC_WAIT));
}