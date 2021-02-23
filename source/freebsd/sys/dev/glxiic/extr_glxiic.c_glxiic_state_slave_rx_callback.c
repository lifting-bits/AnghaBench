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
struct glxiic_softc {int /*<<< orphan*/  iicbus; int /*<<< orphan*/  smb_res; } ;

/* Variables and functions */
 int /*<<< orphan*/  GLXIIC_ASSERT_LOCKED (struct glxiic_softc*) ; 
 int /*<<< orphan*/  GLXIIC_DEBUG_LOG (char*) ; 
 int /*<<< orphan*/  GLXIIC_SMB_SDA ; 
 int GLXIIC_SMB_STS_BER_BIT ; 
 int GLXIIC_SMB_STS_NMATCH_BIT ; 
 int GLXIIC_SMB_STS_SDAST_BIT ; 
 int GLXIIC_SMB_STS_SLVSTP_BIT ; 
 int /*<<< orphan*/  GLXIIC_STATE_IDLE ; 
 int IIC_EBUSERR ; 
 int IIC_ESTATUS ; 
 int IIC_NOERR ; 
 int /*<<< orphan*/  INTR_RECEIVE ; 
 int /*<<< orphan*/  INTR_STOP ; 
 int bus_read_1 (int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int glxiic_handle_slave_match_locked (struct glxiic_softc*,int) ; 
 int /*<<< orphan*/  glxiic_set_state_locked (struct glxiic_softc*,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  glxiic_start_timeout_locked (struct glxiic_softc*) ; 
 int /*<<< orphan*/  iicbus_intr (int /*<<< orphan*/ ,int /*<<< orphan*/ ,int*) ; 

__attribute__((used)) static int
glxiic_state_slave_rx_callback(struct glxiic_softc *sc, uint8_t status)
{
	uint8_t data;

	GLXIIC_ASSERT_LOCKED(sc);

	if ((status & GLXIIC_SMB_STS_BER_BIT) != 0) {
		GLXIIC_DEBUG_LOG("bus error in slave rx");
		return (IIC_EBUSERR);
	}

	if ((status & GLXIIC_SMB_STS_SLVSTP_BIT) != 0) {
		iicbus_intr(sc->iicbus, INTR_STOP, NULL);
		glxiic_set_state_locked(sc, GLXIIC_STATE_IDLE);
		return (IIC_NOERR);
	}

	if ((status & GLXIIC_SMB_STS_NMATCH_BIT) != 0) {
		/* Handle repeated start in slave mode. */
		return (glxiic_handle_slave_match_locked(sc, status));
	}

	if ((status & GLXIIC_SMB_STS_SDAST_BIT) == 0) {
		GLXIIC_DEBUG_LOG("no pending data in slave rx");
		return (IIC_ESTATUS);
	}

	data = bus_read_1(sc->smb_res, GLXIIC_SMB_SDA);
	iicbus_intr(sc->iicbus, INTR_RECEIVE, &data);

	glxiic_start_timeout_locked(sc);

	return (IIC_NOERR);
}