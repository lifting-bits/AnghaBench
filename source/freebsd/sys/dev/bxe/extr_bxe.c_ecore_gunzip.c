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
struct bxe_softc {int dummy; } ;

/* Variables and functions */
 int /*<<< orphan*/  BLOGD (struct bxe_softc*,int /*<<< orphan*/ ,char*) ; 
 int /*<<< orphan*/  DBG_LOAD ; 
 int FALSE ; 

__attribute__((used)) static int
ecore_gunzip(struct bxe_softc *sc,
             const uint8_t    *zbuf,
             int              len)
{
    /* XXX : Implement... */
    BLOGD(sc, DBG_LOAD, "ECORE_GUNZIP NOT IMPLEMENTED\n");
    return (FALSE);
}