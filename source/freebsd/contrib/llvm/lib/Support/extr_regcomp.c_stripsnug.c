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
struct re_guts {int nstates; int /*<<< orphan*/ * strip; } ;
struct parse {int slen; int /*<<< orphan*/ * strip; } ;
typedef  int /*<<< orphan*/  sop ;

/* Variables and functions */
 int /*<<< orphan*/  REG_ESPACE ; 
 int /*<<< orphan*/  SETERROR (int /*<<< orphan*/ ) ; 
 int SIZE_MAX ; 
 scalar_t__ realloc (char*,int) ; 

__attribute__((used)) static void
stripsnug(struct parse *p, struct re_guts *g)
{
	g->nstates = p->slen;
	if ((uintptr_t)p->slen > SIZE_MAX / sizeof(sop)) {
		g->strip = p->strip;
		SETERROR(REG_ESPACE);
		return;
	}

	g->strip = (sop *)realloc((char *)p->strip, p->slen * sizeof(sop));
	if (g->strip == NULL) {
		SETERROR(REG_ESPACE);
		g->strip = p->strip;
	}
}