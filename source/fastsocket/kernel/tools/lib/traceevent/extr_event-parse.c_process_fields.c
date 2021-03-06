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
struct print_flag_sym {struct print_flag_sym* next; int /*<<< orphan*/ * str; int /*<<< orphan*/ * value; } ;
struct print_arg {int dummy; } ;
struct event_format {int dummy; } ;
typedef  enum event_type { ____Placeholder_event_type } event_type ;

/* Variables and functions */
 int EVENT_DELIM ; 
 int EVENT_ERROR ; 
 int EVENT_OP ; 
 struct print_arg* alloc_arg () ; 
 char* arg_eval (struct print_arg*) ; 
 struct print_flag_sym* calloc (int,int) ; 
 int /*<<< orphan*/  free_arg (struct print_arg*) ; 
 int /*<<< orphan*/  free_flag_sym (struct print_flag_sym*) ; 
 int /*<<< orphan*/  free_token (char*) ; 
 int process_arg (struct event_format*,struct print_arg*,char**) ; 
 int process_op (struct event_format*,struct print_arg*,char**) ; 
 int read_token_item (char**) ; 
 scalar_t__ strcmp (char*,char*) ; 
 void* strdup (char*) ; 
 scalar_t__ test_type_token (int,char*,int,char*) ; 

__attribute__((used)) static enum event_type
process_fields(struct event_format *event, struct print_flag_sym **list, char **tok)
{
	enum event_type type;
	struct print_arg *arg = NULL;
	struct print_flag_sym *field;
	char *token = *tok;
	char *value;

	do {
		free_token(token);
		type = read_token_item(&token);
		if (test_type_token(type, token, EVENT_OP, "{"))
			break;

		arg = alloc_arg();
		if (!arg)
			goto out_free;

		free_token(token);
		type = process_arg(event, arg, &token);

		if (type == EVENT_OP)
			type = process_op(event, arg, &token);

		if (type == EVENT_ERROR)
			goto out_free;

		if (test_type_token(type, token, EVENT_DELIM, ","))
			goto out_free;

		field = calloc(1, sizeof(*field));
		if (!field)
			goto out_free;

		value = arg_eval(arg);
		if (value == NULL)
			goto out_free_field;
		field->value = strdup(value);
		if (field->value == NULL)
			goto out_free_field;

		free_arg(arg);
		arg = alloc_arg();
		if (!arg)
			goto out_free;

		free_token(token);
		type = process_arg(event, arg, &token);
		if (test_type_token(type, token, EVENT_OP, "}"))
			goto out_free_field;

		value = arg_eval(arg);
		if (value == NULL)
			goto out_free_field;
		field->str = strdup(value);
		if (field->str == NULL)
			goto out_free_field;
		free_arg(arg);
		arg = NULL;

		*list = field;
		list = &field->next;

		free_token(token);
		type = read_token_item(&token);
	} while (type == EVENT_DELIM && strcmp(token, ",") == 0);

	*tok = token;
	return type;

out_free_field:
	free_flag_sym(field);
out_free:
	free_arg(arg);
	free_token(token);
	*tok = NULL;

	return EVENT_ERROR;
}