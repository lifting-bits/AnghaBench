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
typedef  int /*<<< orphan*/  u_char ;
struct aml8726_iic_softc {int dummy; } ;
typedef  int /*<<< orphan*/  device_t ;

/* Variables and functions */
 int /*<<< orphan*/  AML_I2C_CTRL_REG ; 
 int /*<<< orphan*/  AML_I2C_LOCK (struct aml8726_iic_softc*) ; 
 int AML_I2C_MANUAL_EN ; 
 int AML_I2C_MANUAL_SCL_O ; 
 int AML_I2C_MANUAL_SDA_O ; 
 int /*<<< orphan*/  AML_I2C_UNLOCK (struct aml8726_iic_softc*) ; 
 int CSR_READ_4 (struct aml8726_iic_softc*,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  CSR_WRITE_4 (struct aml8726_iic_softc*,int /*<<< orphan*/ ,int) ; 
 int /*<<< orphan*/  DELAY (int) ; 
 int IIC_ENOADDR ; 
 struct aml8726_iic_softc* device_get_softc (int /*<<< orphan*/ ) ; 

__attribute__((used)) static int
aml8726_iic_reset(device_t dev, u_char speed, u_char addr, u_char *oldaddr)
{
	struct aml8726_iic_softc *sc = device_get_softc(dev);

	AML_I2C_LOCK(sc);

	CSR_WRITE_4(sc, AML_I2C_CTRL_REG,
	    (CSR_READ_4(sc, AML_I2C_CTRL_REG) | AML_I2C_MANUAL_SDA_O |
	    AML_I2C_MANUAL_SCL_O | AML_I2C_MANUAL_EN));

	AML_I2C_UNLOCK(sc);

	/* Wait for 10 usec */
	DELAY(10);

	return (IIC_ENOADDR);
}