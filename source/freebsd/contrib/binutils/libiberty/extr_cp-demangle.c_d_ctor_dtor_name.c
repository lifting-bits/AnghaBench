#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_9__   TYPE_4__ ;
typedef  struct TYPE_8__   TYPE_3__ ;
typedef  struct TYPE_7__   TYPE_2__ ;
typedef  struct TYPE_6__   TYPE_1__ ;

/* Type definitions */
struct demangle_component {int dummy; } ;
struct d_info {TYPE_4__* last_name; int /*<<< orphan*/  expansion; } ;
typedef  enum gnu_v3_dtor_kinds { ____Placeholder_gnu_v3_dtor_kinds } gnu_v3_dtor_kinds ;
typedef  enum gnu_v3_ctor_kinds { ____Placeholder_gnu_v3_ctor_kinds } gnu_v3_ctor_kinds ;
struct TYPE_7__ {scalar_t__ len; } ;
struct TYPE_6__ {scalar_t__ len; } ;
struct TYPE_8__ {TYPE_2__ s_string; TYPE_1__ s_name; } ;
struct TYPE_9__ {scalar_t__ type; TYPE_3__ u; } ;

/* Variables and functions */
 scalar_t__ DEMANGLE_COMPONENT_NAME ; 
 scalar_t__ DEMANGLE_COMPONENT_SUB_STD ; 
 int /*<<< orphan*/  d_advance (struct d_info*,int) ; 
 struct demangle_component* d_make_ctor (struct d_info*,int,TYPE_4__*) ; 
 struct demangle_component* d_make_dtor (struct d_info*,int,TYPE_4__*) ; 
 int d_peek_char (struct d_info*) ; 
 int /*<<< orphan*/  d_peek_next_char (struct d_info*) ; 
 int gnu_v3_base_object_ctor ; 
 int gnu_v3_base_object_dtor ; 
 int gnu_v3_complete_object_allocating_ctor ; 
 int gnu_v3_complete_object_ctor ; 
 int gnu_v3_complete_object_dtor ; 
 int gnu_v3_deleting_dtor ; 

__attribute__((used)) static struct demangle_component *
d_ctor_dtor_name (struct d_info *di)
{
  if (di->last_name != NULL)
    {
      if (di->last_name->type == DEMANGLE_COMPONENT_NAME)
	di->expansion += di->last_name->u.s_name.len;
      else if (di->last_name->type == DEMANGLE_COMPONENT_SUB_STD)
	di->expansion += di->last_name->u.s_string.len;
    }
  switch (d_peek_char (di))
    {
    case 'C':
      {
	enum gnu_v3_ctor_kinds kind;

	switch (d_peek_next_char (di))
	  {
	  case '1':
	    kind = gnu_v3_complete_object_ctor;
	    break;
	  case '2':
	    kind = gnu_v3_base_object_ctor;
	    break;
	  case '3':
	    kind = gnu_v3_complete_object_allocating_ctor;
	    break;
	  default:
	    return NULL;
	  }
	d_advance (di, 2);
	return d_make_ctor (di, kind, di->last_name);
      }

    case 'D':
      {
	enum gnu_v3_dtor_kinds kind;

	switch (d_peek_next_char (di))
	  {
	  case '0':
	    kind = gnu_v3_deleting_dtor;
	    break;
	  case '1':
	    kind = gnu_v3_complete_object_dtor;
	    break;
	  case '2':
	    kind = gnu_v3_base_object_dtor;
	    break;
	  default:
	    return NULL;
	  }
	d_advance (di, 2);
	return d_make_dtor (di, kind, di->last_name);
      }

    default:
      return NULL;
    }
}