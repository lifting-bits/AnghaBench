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
struct aac_softc {int dummy; } ;

/* Variables and functions */
 int /*<<< orphan*/  AAC_MEM0_SETREG4 (struct aac_softc*,int /*<<< orphan*/ ,int) ; 
 int /*<<< orphan*/  AAC_SRC_IDBR ; 
 int AAC_SRC_IDR_SHIFT ; 
 char* HBA_FLAGS_DBG_FUNCTION_ENTRY_B ; 
 int /*<<< orphan*/  fwprintf (struct aac_softc*,char*,char*) ; 

__attribute__((used)) static void
aac_src_qnotify(struct aac_softc *sc, int qbit)
{
	fwprintf(sc, HBA_FLAGS_DBG_FUNCTION_ENTRY_B, "");

	AAC_MEM0_SETREG4(sc, AAC_SRC_IDBR, qbit << AAC_SRC_IDR_SHIFT);
}