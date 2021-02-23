#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_5__   TYPE_2__ ;
typedef  struct TYPE_4__   TYPE_1__ ;

/* Type definitions */
typedef  TYPE_1__* decl_t ;
struct TYPE_5__ {scalar_t__ name; } ;
struct TYPE_4__ {scalar_t__ mode; } ;

/* Variables and functions */
 TYPE_2__* DECL_AUTOMATON (TYPE_1__* const) ; 
 scalar_t__ dm_automaton ; 
 int /*<<< orphan*/  gcc_assert (int) ; 
 scalar_t__ strcmp (scalar_t__,scalar_t__) ; 

__attribute__((used)) static int
automaton_decl_eq_p (const void* automaton_decl_1,
		     const void* automaton_decl_2)
{
  const decl_t decl1 = (decl_t) automaton_decl_1;
  const decl_t decl2 = (decl_t) automaton_decl_2;

  gcc_assert (decl1->mode == dm_automaton
	      && DECL_AUTOMATON (decl1)->name
	      && decl2->mode == dm_automaton
	      && DECL_AUTOMATON (decl2)->name);
  return strcmp (DECL_AUTOMATON (decl1)->name,
		 DECL_AUTOMATON (decl2)->name) == 0;
}