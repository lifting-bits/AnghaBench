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
struct type {int dummy; } ;
struct dwarf2_cu {int dummy; } ;
struct die_info {int /*<<< orphan*/  type; } ;

/* Variables and functions */
 int /*<<< orphan*/  TYPE_RESTRICT (struct type*) ; 
 int /*<<< orphan*/  TYPE_VOLATILE (struct type*) ; 
 struct type* die_type (struct die_info*,struct dwarf2_cu*) ; 
 int /*<<< orphan*/  make_cvr_type (int,int /*<<< orphan*/ ,int /*<<< orphan*/ ,struct type*,int /*<<< orphan*/ ) ; 

__attribute__((used)) static void
read_tag_const_type (struct die_info *die, struct dwarf2_cu *cu)
{
  struct type *base_type;

  if (die->type)
    {
      return;
    }

  base_type = die_type (die, cu);
  die->type = make_cvr_type (1, TYPE_VOLATILE (base_type),
                             TYPE_RESTRICT (base_type), base_type, 0);
}