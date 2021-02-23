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
struct radix_node {char* rn_key; char* rn_mask; } ;

/* Variables and functions */
 int LEN (char*) ; 
 int min (int,int) ; 
 char* rn_ones ; 

__attribute__((used)) static int
rn_satisfies_leaf(char *trial, struct radix_node *leaf, int skip)
{
	char *cp = trial, *cp2 = leaf->rn_key, *cp3 = leaf->rn_mask;
	char *cplim;
	int length = min(LEN(cp), LEN(cp2));

	if (cp3 == NULL)
		cp3 = rn_ones;
	else
		length = min(length, LEN(cp3));
	cplim = cp + length; cp3 += skip; cp2 += skip;
	for (cp += skip; cp < cplim; cp++, cp2++, cp3++)
		if ((*cp ^ *cp2) & *cp3)
			return (0);
	return (1);
}