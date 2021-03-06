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
struct trace_seq {int dummy; } ;
struct trace_iterator {int /*<<< orphan*/  ent; struct trace_seq seq; } ;
struct trace_event {int dummy; } ;
struct ftrace_entry {int /*<<< orphan*/  parent_ip; int /*<<< orphan*/  ip; } ;
typedef  enum print_line_t { ____Placeholder_print_line_t } print_line_t ;

/* Variables and functions */
 int /*<<< orphan*/  SEQ_PUT_HEX_FIELD (struct trace_seq*,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  trace_assign_type (struct ftrace_entry*,int /*<<< orphan*/ ) ; 
 int trace_handle_return (struct trace_seq*) ; 

__attribute__((used)) static enum print_line_t trace_fn_hex(struct trace_iterator *iter, int flags,
				      struct trace_event *event)
{
	struct ftrace_entry *field;
	struct trace_seq *s = &iter->seq;

	trace_assign_type(field, iter->ent);

	SEQ_PUT_HEX_FIELD(s, field->ip);
	SEQ_PUT_HEX_FIELD(s, field->parent_ip);

	return trace_handle_return(s);
}