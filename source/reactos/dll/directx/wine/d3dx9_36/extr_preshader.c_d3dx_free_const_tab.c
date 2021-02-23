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
struct d3dx_const_tab {int /*<<< orphan*/  const_set; int /*<<< orphan*/  inputs_param; int /*<<< orphan*/  inputs; } ;

/* Variables and functions */
 int /*<<< orphan*/  GetProcessHeap () ; 
 int /*<<< orphan*/  HeapFree (int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 

__attribute__((used)) static void d3dx_free_const_tab(struct d3dx_const_tab *ctab)
{
    HeapFree(GetProcessHeap(), 0, ctab->inputs);
    HeapFree(GetProcessHeap(), 0, ctab->inputs_param);
    HeapFree(GetProcessHeap(), 0, ctab->const_set);
}