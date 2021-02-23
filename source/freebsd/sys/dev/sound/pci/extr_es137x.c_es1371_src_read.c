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
struct es_info {int dummy; } ;

/* Variables and functions */
 int ES1371_DIS_P1 ; 
 int ES1371_DIS_P2 ; 
 int ES1371_DIS_R1 ; 
 int ES1371_DIS_SRC ; 
 int /*<<< orphan*/  ES1371_REG_SMPRATE ; 
 int ES1371_SRC_RAM_ADDRO (unsigned short) ; 
 unsigned int ES1371_SRC_RAM_DATAI (int) ; 
 int es1371_wait_src_ready (struct es_info*) ; 
 int /*<<< orphan*/  es_wr (struct es_info*,int /*<<< orphan*/ ,int,int) ; 

__attribute__((used)) static unsigned int
es1371_src_read(struct es_info *es, unsigned short reg)
{
  	uint32_t r;

  	r = es1371_wait_src_ready(es) & (ES1371_DIS_SRC | ES1371_DIS_P1 |
	    ES1371_DIS_P2 | ES1371_DIS_R1);
  	r |= ES1371_SRC_RAM_ADDRO(reg);
  	es_wr(es, ES1371_REG_SMPRATE, r, 4);
  	return (ES1371_SRC_RAM_DATAI(es1371_wait_src_ready(es)));
}