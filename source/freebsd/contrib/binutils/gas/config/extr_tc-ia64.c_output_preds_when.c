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
typedef  int /*<<< orphan*/  unw_rec_list ;

/* Variables and functions */
 int /*<<< orphan*/ * alloc_record (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  preds_when ; 

__attribute__((used)) static unw_rec_list *
output_preds_when ()
{
  unw_rec_list *ptr = alloc_record (preds_when);
  return ptr;
}