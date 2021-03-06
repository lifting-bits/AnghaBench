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
typedef  scalar_t__ fz_bidi_chartype ;

/* Variables and functions */
 scalar_t__ BDI_B ; 
 scalar_t__ BDI_BN ; 

int fz_bidi_resolve_paragraphs(fz_bidi_chartype *types, int cch)
{
	int ich;

	// skip characters not of type B
	for(ich = 0; ich < cch && types[ich] != BDI_B; ich++)
		;
	// stop after first B, make it a BN for use in the next steps
	if (ich < cch && types[ich] == BDI_B)
		types[ich++] = BDI_BN;
	return ich;
}