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
struct nfsmb_softc {int dummy; } ;
typedef  int /*<<< orphan*/  device_t ;

/* Variables and functions */
 int /*<<< orphan*/  NFSMB_DEBUG (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  NFSMB_LOCK (struct nfsmb_softc*) ; 
 int /*<<< orphan*/  NFSMB_SMBOUTB (struct nfsmb_softc*,scalar_t__,int) ; 
 int /*<<< orphan*/  NFSMB_UNLOCK (struct nfsmb_softc*) ; 
 scalar_t__ SMB_ADDR ; 
 scalar_t__ SMB_BCNT ; 
 scalar_t__ SMB_CMD ; 
 scalar_t__ SMB_DATA ; 
 int SMB_EINVAL ; 
 scalar_t__ SMB_PRTCL ; 
 int SMB_PRTCL_BLOCK_DATA ; 
 int SMB_PRTCL_WRITE ; 
 scalar_t__ device_get_softc (int /*<<< orphan*/ ) ; 
 int nfsmb_wait (struct nfsmb_softc*) ; 
 int /*<<< orphan*/  printf (char*,int,int,char,int) ; 

__attribute__((used)) static int
nfsmb_bwrite(device_t dev, u_char slave, char cmd, u_char count, char *buf)
{
	struct nfsmb_softc *sc = (struct nfsmb_softc *)device_get_softc(dev);
	u_char i;
	int error;

	if (count < 1 || count > 32)
		return (SMB_EINVAL);

	NFSMB_LOCK(sc);
	NFSMB_SMBOUTB(sc, SMB_CMD, cmd);
	NFSMB_SMBOUTB(sc, SMB_BCNT, count);
	for (i = 0; i < count; i++)
		NFSMB_SMBOUTB(sc, SMB_DATA + i, buf[i]);
	NFSMB_SMBOUTB(sc, SMB_ADDR, slave);
	NFSMB_SMBOUTB(sc, SMB_PRTCL, SMB_PRTCL_WRITE | SMB_PRTCL_BLOCK_DATA);

	error = nfsmb_wait(sc);

	NFSMB_DEBUG(printf("nfsmb: WRITEBLK to 0x%x, count=0x%x, cmd=0x%x, error=0x%x", slave, count, cmd, error));
	NFSMB_UNLOCK(sc);

	return (error);
}