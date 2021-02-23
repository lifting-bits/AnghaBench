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
struct alpm_softc {int dummy; } ;
typedef  int /*<<< orphan*/  device_t ;

/* Variables and functions */
 int /*<<< orphan*/  ALPM_DEBUG (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  ALPM_LOCK (struct alpm_softc*) ; 
 char ALPM_SMBINB (struct alpm_softc*,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  ALPM_SMBOUTB (struct alpm_softc*,int /*<<< orphan*/ ,int) ; 
 int /*<<< orphan*/  ALPM_UNLOCK (struct alpm_softc*) ; 
 int LSB ; 
 int /*<<< orphan*/  SMBCMD ; 
 int /*<<< orphan*/  SMBHADDR ; 
 int /*<<< orphan*/  SMBHCMD ; 
 int /*<<< orphan*/  SMBHDATA ; 
 int /*<<< orphan*/  SMBSTART ; 
 int SMBWRBYTE ; 
 int SMB_EBUSY ; 
 int SMB_ENOERR ; 
 int /*<<< orphan*/  alpm_clear (struct alpm_softc*) ; 
 int /*<<< orphan*/  alpm_idle (struct alpm_softc*) ; 
 int alpm_wait (struct alpm_softc*) ; 
 scalar_t__ device_get_softc (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  printf (char*,int,char,char,int) ; 

__attribute__((used)) static int
alpm_readb(device_t dev, u_char slave, char cmd, char *byte)
{
	struct alpm_softc *sc = (struct alpm_softc *)device_get_softc(dev);
	int error;

	ALPM_LOCK(sc);
	alpm_clear(sc);
	if (!alpm_idle(sc)) {
		ALPM_UNLOCK(sc);
		return (SMB_EBUSY);
	}

	ALPM_SMBOUTB(sc, SMBHADDR, slave | LSB);
	ALPM_SMBOUTB(sc, SMBCMD, SMBWRBYTE);
	ALPM_SMBOUTB(sc, SMBHCMD, cmd);
	ALPM_SMBOUTB(sc, SMBSTART, 0xff);

	if ((error = alpm_wait(sc)) == SMB_ENOERR)
		*byte = ALPM_SMBINB(sc, SMBHDATA);

	ALPM_DEBUG(printf("alpm: READB from 0x%x, cmd=0x%x, byte=0x%x, error=0x%x\n", slave, cmd, *byte, error));
	ALPM_UNLOCK(sc);

	return (error);
}