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
typedef  int u_char ;
struct amdsmb_softc {int dummy; } ;
typedef  int /*<<< orphan*/  device_t ;

/* Variables and functions */
 int /*<<< orphan*/  AMDSMB_DEBUG (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  AMDSMB_LOCK (struct amdsmb_softc*) ; 
 int /*<<< orphan*/  AMDSMB_UNLOCK (struct amdsmb_softc*) ; 
 int /*<<< orphan*/  SMB_ADDR ; 
 int /*<<< orphan*/  SMB_DATA ; 
 int SMB_ENOERR ; 
 int /*<<< orphan*/  SMB_PRTCL ; 
 int SMB_PRTCL_BYTE ; 
 int SMB_PRTCL_READ ; 
 int /*<<< orphan*/  amdsmb_ec_read (struct amdsmb_softc*,int /*<<< orphan*/ ,char*) ; 
 int /*<<< orphan*/  amdsmb_ec_write (struct amdsmb_softc*,int /*<<< orphan*/ ,int) ; 
 int amdsmb_wait (struct amdsmb_softc*) ; 
 scalar_t__ device_get_softc (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  printf (char*,int,char,int) ; 

__attribute__((used)) static int
amdsmb_recvb(device_t dev, u_char slave, char *byte)
{
	struct amdsmb_softc *sc = (struct amdsmb_softc *)device_get_softc(dev);
	int error;

	AMDSMB_LOCK(sc);
	amdsmb_ec_write(sc, SMB_ADDR, slave);
	amdsmb_ec_write(sc, SMB_PRTCL, SMB_PRTCL_READ | SMB_PRTCL_BYTE);

	if ((error = amdsmb_wait(sc)) == SMB_ENOERR)
		amdsmb_ec_read(sc, SMB_DATA, byte);

	AMDSMB_DEBUG(printf("amdsmb: RECVB from 0x%x, byte=0x%x, error=0x%x\n",
	    slave, *byte, error));
	AMDSMB_UNLOCK(sc);

	return (error);
}