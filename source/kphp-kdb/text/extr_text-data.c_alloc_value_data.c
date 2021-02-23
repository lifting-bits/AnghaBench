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
struct value_data {int fields_mask; scalar_t__ zero_mask; } ;

/* Variables and functions */
 int extra_mask_intcount (int) ; 
 struct value_data* zmalloc (int) ; 

struct value_data *alloc_value_data (int fields_mask) {
  struct value_data *V = zmalloc (4 + 4 * extra_mask_intcount (fields_mask));
  V->fields_mask = fields_mask;
  V->zero_mask = 0;
  return V;
}