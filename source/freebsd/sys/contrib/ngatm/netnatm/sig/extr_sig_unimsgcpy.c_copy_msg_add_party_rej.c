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
typedef  size_t u_int ;
struct uni_add_party_rej {int /*<<< orphan*/  unrec; int /*<<< orphan*/  crankback; int /*<<< orphan*/ * git; int /*<<< orphan*/  uu; int /*<<< orphan*/  epref; int /*<<< orphan*/  cause; } ;

/* Variables and functions */
 scalar_t__ IE_ISGOOD (int /*<<< orphan*/ ) ; 
 size_t UNI_NUM_IE_GIT ; 

void
copy_msg_add_party_rej(struct uni_add_party_rej *src, struct uni_add_party_rej *dst)
{
	u_int s, d;

	if(IE_ISGOOD(src->cause))
		dst->cause = src->cause;
	if(IE_ISGOOD(src->epref))
		dst->epref = src->epref;
	if(IE_ISGOOD(src->uu))
		dst->uu = src->uu;
	for(s = d = 0; s < UNI_NUM_IE_GIT; s++)
		if(IE_ISGOOD(src->git[s]))
			dst->git[d++] = src->git[s];
	if(IE_ISGOOD(src->crankback))
		dst->crankback = src->crankback;
	if(IE_ISGOOD(src->unrec))
		dst->unrec = src->unrec;
}