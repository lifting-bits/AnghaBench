#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_11__   TYPE_3__ ;
typedef  struct TYPE_10__   TYPE_2__ ;
typedef  struct TYPE_9__   TYPE_1__ ;

/* Type definitions */
struct TYPE_9__ {int encoding; int mixed_encoding; } ;
struct TYPE_10__ {TYPE_1__ b; } ;
struct object {void* pc_begin; TYPE_2__ s; } ;
struct dwarf_cie {int dummy; } ;
struct TYPE_11__ {scalar_t__ CIE_delta; int /*<<< orphan*/  pc_begin; } ;
typedef  TYPE_3__ fde ;
typedef  int _Unwind_Ptr ;

/* Variables and functions */
 int DW_EH_PE_absptr ; 
 int DW_EH_PE_omit ; 
 int base_from_object (int,struct object*) ; 
 struct dwarf_cie* get_cie (TYPE_3__ const*) ; 
 int get_cie_encoding (struct dwarf_cie const*) ; 
 int /*<<< orphan*/  last_fde (struct object*,TYPE_3__ const*) ; 
 TYPE_3__* next_fde (TYPE_3__ const*) ; 
 int /*<<< orphan*/  read_encoded_value_with_base (int,int,int /*<<< orphan*/ ,int*) ; 
 int size_of_encoded_value (int) ; 

__attribute__((used)) static size_t
classify_object_over_fdes (struct object *ob, const fde *this_fde)
{
  const struct dwarf_cie *last_cie = 0;
  size_t count = 0;
  int encoding = DW_EH_PE_absptr;
  _Unwind_Ptr base = 0;

  for (; ! last_fde (ob, this_fde); this_fde = next_fde (this_fde))
    {
      const struct dwarf_cie *this_cie;
      _Unwind_Ptr mask, pc_begin;

      /* Skip CIEs.  */
      if (this_fde->CIE_delta == 0)
	continue;

      /* Determine the encoding for this FDE.  Note mixed encoded
	 objects for later.  */
      this_cie = get_cie (this_fde);
      if (this_cie != last_cie)
	{
	  last_cie = this_cie;
	  encoding = get_cie_encoding (this_cie);
	  base = base_from_object (encoding, ob);
	  if (ob->s.b.encoding == DW_EH_PE_omit)
	    ob->s.b.encoding = encoding;
	  else if (ob->s.b.encoding != encoding)
	    ob->s.b.mixed_encoding = 1;
	}

      read_encoded_value_with_base (encoding, base, this_fde->pc_begin,
				    &pc_begin);

      /* Take care to ignore link-once functions that were removed.
	 In these cases, the function address will be NULL, but if
	 the encoding is smaller than a pointer a true NULL may not
	 be representable.  Assume 0 in the representable bits is NULL.  */
      mask = size_of_encoded_value (encoding);
      if (mask < sizeof (void *))
	mask = (1L << (mask << 3)) - 1;
      else
	mask = -1;

      if ((pc_begin & mask) == 0)
	continue;

      count += 1;
      if ((void *) pc_begin < ob->pc_begin)
	ob->pc_begin = (void *) pc_begin;
    }

  return count;
}