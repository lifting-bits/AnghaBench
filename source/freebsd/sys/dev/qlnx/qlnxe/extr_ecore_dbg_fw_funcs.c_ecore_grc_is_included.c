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
typedef  enum dbg_grc_params { ____Placeholder_dbg_grc_params } dbg_grc_params ;

/* Variables and functions */
 scalar_t__ ecore_grc_get_param (struct ecore_hwfn*,int) ; 

__attribute__((used)) static bool ecore_grc_is_included(struct ecore_hwfn *p_hwfn,
								  enum dbg_grc_params grc_param)
{
	return ecore_grc_get_param(p_hwfn, grc_param) > 0;
}