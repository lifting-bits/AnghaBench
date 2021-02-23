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
struct partial_symtab {int dummy; } ;
struct partial_symbol {int dummy; } ;
typedef  int /*<<< orphan*/  CORE_ADDR ;

/* Variables and functions */
 int /*<<< orphan*/  find_pc_mapped_section (int /*<<< orphan*/ ) ; 
 struct partial_symbol* find_pc_sect_psymbol (struct partial_symtab*,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 

struct partial_symbol *
find_pc_psymbol (struct partial_symtab *psymtab, CORE_ADDR pc)
{
  return find_pc_sect_psymbol (psymtab, pc, find_pc_mapped_section (pc));
}