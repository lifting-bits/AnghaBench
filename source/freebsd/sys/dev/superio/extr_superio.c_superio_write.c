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
struct superio_devinfo {int /*<<< orphan*/  ldn; } ;
struct siosc {int dummy; } ;
typedef  int /*<<< orphan*/  device_t ;

/* Variables and functions */
 struct superio_devinfo* device_get_ivars (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  device_get_parent (int /*<<< orphan*/ ) ; 
 struct siosc* device_get_softc (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  sio_conf_enter (struct siosc*) ; 
 int /*<<< orphan*/  sio_conf_exit (struct siosc*) ; 
 int /*<<< orphan*/  sio_ldn_write (struct siosc*,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 

void
superio_write(device_t dev, uint8_t reg, uint8_t val)
{
	device_t sio_dev = device_get_parent(dev);
	struct siosc *sc = device_get_softc(sio_dev);
	struct superio_devinfo *dinfo = device_get_ivars(dev);

	sio_conf_enter(sc);
	sio_ldn_write(sc, dinfo->ldn, reg, val);
	sio_conf_exit(sc);
}