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
struct TYPE_5__ {TYPE_1__* buffer; } ;
typedef  TYPE_2__ pretty_printer ;
struct TYPE_4__ {scalar_t__ line_length; int /*<<< orphan*/  obstack; } ;

/* Variables and functions */
 int /*<<< orphan*/  obstack_1grow (int /*<<< orphan*/ ,char) ; 

void
pp_base_newline (pretty_printer *pp)
{
  obstack_1grow (pp->buffer->obstack, '\n');
  pp->buffer->line_length = 0;
}