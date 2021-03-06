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
typedef  int uint32_t ;
struct iwn_softc {int dummy; } ;

/* Variables and functions */
 int /*<<< orphan*/  IWN_BARRIER_WRITE (struct iwn_softc*) ; 
 int IWN_PRPH_DWORD ; 
 int /*<<< orphan*/  IWN_PRPH_WADDR ; 
 int /*<<< orphan*/  IWN_PRPH_WDATA ; 
 int /*<<< orphan*/  IWN_WRITE (struct iwn_softc*,int /*<<< orphan*/ ,int) ; 

__attribute__((used)) static __inline void
iwn_prph_write(struct iwn_softc *sc, uint32_t addr, uint32_t data)
{
	IWN_WRITE(sc, IWN_PRPH_WADDR, IWN_PRPH_DWORD | addr);
	IWN_BARRIER_WRITE(sc);
	IWN_WRITE(sc, IWN_PRPH_WDATA, data);
}