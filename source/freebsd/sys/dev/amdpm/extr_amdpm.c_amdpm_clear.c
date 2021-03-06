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
struct amdpm_softc {int dummy; } ;

/* Variables and functions */
 int /*<<< orphan*/  AMDPM_LOCK_ASSERT (struct amdpm_softc*) ; 
 int /*<<< orphan*/  AMDPM_SMBOUTW (struct amdpm_softc*,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  AMDSMB_GLOBAL_STATUS ; 
 int /*<<< orphan*/  AMDSMB_GS_CLEAR_STS ; 
 int /*<<< orphan*/  DELAY (int) ; 

__attribute__((used)) static int
amdpm_clear(struct amdpm_softc *sc)
{

	AMDPM_LOCK_ASSERT(sc);
	AMDPM_SMBOUTW(sc, AMDSMB_GLOBAL_STATUS, AMDSMB_GS_CLEAR_STS);
	DELAY(10);

	return (0);
}