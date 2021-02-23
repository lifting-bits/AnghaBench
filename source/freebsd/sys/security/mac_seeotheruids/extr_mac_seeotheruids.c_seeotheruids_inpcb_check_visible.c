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
struct ucred {int dummy; } ;
struct label {int dummy; } ;
struct inpcb {int /*<<< orphan*/  inp_cred; } ;

/* Variables and functions */
 int seeotheruids_check (struct ucred*,int /*<<< orphan*/ ) ; 

__attribute__((used)) static int
seeotheruids_inpcb_check_visible(struct ucred *cred, struct inpcb *inp,
    struct label *inplabel)
{

	return (seeotheruids_check(cred, inp->inp_cred));
}