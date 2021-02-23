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
typedef  int /*<<< orphan*/  backslashResult ;
typedef  int /*<<< orphan*/  PsqlScanState ;
typedef  int /*<<< orphan*/  PQExpBuffer ;
typedef  int /*<<< orphan*/  ConditionalStack ;

/* Variables and functions */
#define  IFSTATE_ELSE_FALSE 133 
#define  IFSTATE_ELSE_TRUE 132 
#define  IFSTATE_FALSE 131 
#define  IFSTATE_IGNORED 130 
#define  IFSTATE_NONE 129 
#define  IFSTATE_TRUE 128 
 int /*<<< orphan*/  PSQL_CMD_ERROR ; 
 int /*<<< orphan*/  PSQL_CMD_SKIP_LINE ; 
 int conditional_stack_peek (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  conditional_stack_poke (int /*<<< orphan*/ ,int const) ; 
 int /*<<< orphan*/  discard_query_text (int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  ignore_boolean_expression (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  is_true_boolean_expression (int /*<<< orphan*/ ,char*) ; 
 int /*<<< orphan*/  pg_log_error (char*) ; 
 int /*<<< orphan*/  save_query_text_state (int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 

__attribute__((used)) static backslashResult
exec_command_elif(PsqlScanState scan_state, ConditionalStack cstack,
				  PQExpBuffer query_buf)
{
	bool		success = true;

	switch (conditional_stack_peek(cstack))
	{
		case IFSTATE_TRUE:

			/*
			 * Just finished active branch of this \if block.  Update saved
			 * state so we will keep whatever data was put in query_buf by the
			 * active branch.
			 */
			save_query_text_state(scan_state, cstack, query_buf);

			/*
			 * Discard \elif expression and ignore the rest until \endif.
			 * Switch state before reading expression to ensure proper lexer
			 * behavior.
			 */
			conditional_stack_poke(cstack, IFSTATE_IGNORED);
			ignore_boolean_expression(scan_state);
			break;
		case IFSTATE_FALSE:

			/*
			 * Discard any query text added by the just-skipped branch.
			 */
			discard_query_text(scan_state, cstack, query_buf);

			/*
			 * Have not yet found a true expression in this \if block, so this
			 * might be the first.  We have to change state before examining
			 * the expression, or the lexer won't do the right thing.
			 */
			conditional_stack_poke(cstack, IFSTATE_TRUE);
			if (!is_true_boolean_expression(scan_state, "\\elif expression"))
				conditional_stack_poke(cstack, IFSTATE_FALSE);
			break;
		case IFSTATE_IGNORED:

			/*
			 * Discard any query text added by the just-skipped branch.
			 */
			discard_query_text(scan_state, cstack, query_buf);

			/*
			 * Skip expression and move on.  Either the \if block already had
			 * an active section, or whole block is being skipped.
			 */
			ignore_boolean_expression(scan_state);
			break;
		case IFSTATE_ELSE_TRUE:
		case IFSTATE_ELSE_FALSE:
			pg_log_error("\\elif: cannot occur after \\else");
			success = false;
			break;
		case IFSTATE_NONE:
			/* no \if to elif from */
			pg_log_error("\\elif: no matching \\if");
			success = false;
			break;
	}

	return success ? PSQL_CMD_SKIP_LINE : PSQL_CMD_ERROR;
}