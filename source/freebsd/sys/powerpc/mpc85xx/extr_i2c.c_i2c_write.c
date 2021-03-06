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
struct i2c_softc {int /*<<< orphan*/  mutex; } ;
typedef  int /*<<< orphan*/  device_t ;

/* Variables and functions */
 int /*<<< orphan*/  DELAY (int) ; 
 int /*<<< orphan*/  I2C_DATA_REG ; 
 int IIC_NOERR ; 
 struct i2c_softc* device_get_softc (int /*<<< orphan*/ ) ; 
 int i2c_do_wait (int /*<<< orphan*/ ,struct i2c_softc*,int,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  i2c_write_reg (struct i2c_softc*,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  mtx_lock (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  mtx_unlock (int /*<<< orphan*/ *) ; 

__attribute__((used)) static int
i2c_write(device_t dev, const char *buf, int len, int *sent, int timeout)
{
	struct i2c_softc *sc;
	int error;

	sc = device_get_softc(dev);
	*sent = 0;

	mtx_lock(&sc->mutex);
	while (*sent < len) {
		i2c_write_reg(sc, I2C_DATA_REG, *buf++);
		DELAY(1250);

		error = i2c_do_wait(dev, sc, 1, 0);
		if (error) {
			mtx_unlock(&sc->mutex);
			return (error);
		}

		(*sent)++;
	}
	mtx_unlock(&sc->mutex);

	return (IIC_NOERR);
}