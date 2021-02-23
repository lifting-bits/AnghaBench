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
struct blockvector {int dummy; } ;
typedef  int /*<<< orphan*/  CORE_ADDR ;

/* Variables and functions */
 struct blockvector* blockvector_for_pc_sect (int /*<<< orphan*/ ,int /*<<< orphan*/ ,int*,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  find_pc_mapped_section (int /*<<< orphan*/ ) ; 

struct blockvector *
blockvector_for_pc (CORE_ADDR pc, int *pindex)
{
  return blockvector_for_pc_sect (pc, find_pc_mapped_section (pc),
				  pindex, NULL);
}