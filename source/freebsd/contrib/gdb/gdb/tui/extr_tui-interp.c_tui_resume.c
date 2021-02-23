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
struct ui_file {int dummy; } ;

/* Variables and functions */
 struct ui_file* cli_out_set_stream (int /*<<< orphan*/ ,struct ui_file*) ; 
 int /*<<< orphan*/  gdb_setup_readline () ; 
 struct ui_file* gdb_stdout ; 
 int /*<<< orphan*/  tui_enable () ; 
 int /*<<< orphan*/  tui_old_uiout ; 
 scalar_t__ tui_start_enabled ; 

__attribute__((used)) static int
tui_resume (void *data)
{
  struct ui_file *stream;

  /* gdb_setup_readline will change gdb_stdout.  If the TUI was previously
     writing to gdb_stdout, then set it to the new gdb_stdout afterwards.  */

  stream = cli_out_set_stream (tui_old_uiout, gdb_stdout);
  if (stream != gdb_stdout)
    {
      cli_out_set_stream (tui_old_uiout, stream);
      stream = NULL;
    }

  gdb_setup_readline ();

  if (stream != NULL)
    cli_out_set_stream (tui_old_uiout, gdb_stdout);

  if (tui_start_enabled)
    tui_enable ();
  return 1;
}