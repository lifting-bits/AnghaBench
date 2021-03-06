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
struct TYPE_4__ {int /*<<< orphan*/  count; } ;
typedef  int /*<<< orphan*/  HPDF_UINT ;
typedef  TYPE_2__* HPDF_Array ;

/* Variables and functions */

HPDF_UINT
HPDF_Array_Items  (HPDF_Array array)
{
    return array->list->count;
}