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
struct varobj {int dummy; } ;
typedef  enum mi_cmd_result { ____Placeholder_mi_cmd_result } mi_cmd_result ;

/* Variables and functions */
 int MI_CMD_DONE ; 
 int /*<<< orphan*/  error (char*) ; 
 int /*<<< orphan*/  ui_out_field_string (int /*<<< orphan*/ ,char*,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  uiout ; 
 int varobj_get_attributes (struct varobj*) ; 
 struct varobj* varobj_get_handle (char*) ; 
 int /*<<< orphan*/  varobj_get_value (struct varobj*) ; 
 int /*<<< orphan*/  varobj_set_value (struct varobj*,char*) ; 
 char* xstrdup (char*) ; 

enum mi_cmd_result
mi_cmd_var_assign (char *command, char **argv, int argc)
{
  struct varobj *var;
  char *expression;

  if (argc != 2)
    error ("mi_cmd_var_assign: Usage: NAME EXPRESSION.");

  /* Get varobj handle, if a valid var obj name was specified */
  var = varobj_get_handle (argv[0]);
  if (var == NULL)
    error ("mi_cmd_var_assign: Variable object not found");

  /* FIXME: define masks for attributes */
  if (!(varobj_get_attributes (var) & 0x00000001))
    error ("mi_cmd_var_assign: Variable object is not editable");

  expression = xstrdup (argv[1]);

  if (!varobj_set_value (var, expression))
    error ("mi_cmd_var_assign: Could not assign expression to varible object");

  ui_out_field_string (uiout, "value", varobj_get_value (var));
  return MI_CMD_DONE;
}