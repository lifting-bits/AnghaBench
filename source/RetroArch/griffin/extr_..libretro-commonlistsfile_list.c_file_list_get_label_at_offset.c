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
struct TYPE_5__ {TYPE_1__* list; } ;
typedef  TYPE_2__ file_list_t ;
struct TYPE_4__ {char* path; char* label; } ;

/* Variables and functions */

void file_list_get_label_at_offset(const file_list_t *list, size_t idx,
      const char **label)
{
   if (!label || !list)
      return;

   *label = list->list[idx].path;
   if (list->list[idx].label)
      *label = list->list[idx].label;
}