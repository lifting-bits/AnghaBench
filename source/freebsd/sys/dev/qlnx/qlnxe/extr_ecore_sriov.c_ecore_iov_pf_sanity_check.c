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
struct ecore_hwfn {int dummy; } ;

/* Variables and functions */
 int _ecore_iov_pf_sanity_check (struct ecore_hwfn*,int,int) ; 

bool ecore_iov_pf_sanity_check(struct ecore_hwfn *p_hwfn, int vfid)
{
	return _ecore_iov_pf_sanity_check(p_hwfn, vfid, true);
}