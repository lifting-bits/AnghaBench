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
typedef  void u32 ;
struct symbol {int dummy; } ;
struct rb_node {int dummy; } ;

/* Variables and functions */

__attribute__((used)) static u32 *symbol__browser_index(struct symbol *self)
{
	return ((void *)self) - sizeof(struct rb_node) - sizeof(u32);
}