#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_12__   TYPE_6__ ;
typedef  struct TYPE_11__   TYPE_5__ ;
typedef  struct TYPE_10__   TYPE_4__ ;
typedef  struct TYPE_9__   TYPE_3__ ;
typedef  struct TYPE_8__   TYPE_2__ ;
typedef  struct TYPE_7__   TYPE_1__ ;

/* Type definitions */
union tui_line_or_address {int line_no; } ;
typedef  TYPE_5__** tui_win_content ;
struct symtab_and_line {struct symtab* symtab; } ;
struct symtab {int nlines; } ;
typedef  enum tui_scroll_direction { ____Placeholder_tui_scroll_direction } tui_scroll_direction ;
struct TYPE_7__ {int /*<<< orphan*/ * content; } ;
struct TYPE_12__ {TYPE_1__ generic; } ;
struct TYPE_8__ {int line_no; } ;
struct TYPE_9__ {TYPE_2__ line_or_addr; } ;
struct TYPE_10__ {TYPE_3__ source; } ;
struct TYPE_11__ {TYPE_4__ which_element; } ;

/* Variables and functions */
 int FORWARD_SCROLL ; 
 TYPE_6__* TUI_SRC_WIN ; 
 int /*<<< orphan*/  deprecated_selected_frame ; 
 struct symtab* find_pc_symtab (int /*<<< orphan*/ ) ; 
 struct symtab_and_line get_current_source_symtab_and_line () ; 
 int /*<<< orphan*/  get_frame_pc (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  print_source_lines (struct symtab*,int,int,int /*<<< orphan*/ ) ; 

void
tui_vertical_source_scroll (enum tui_scroll_direction scroll_direction,
			    int num_to_scroll)
{
  if (TUI_SRC_WIN->generic.content != NULL)
    {
      union tui_line_or_address l;
      struct symtab *s;
      tui_win_content content = (tui_win_content) TUI_SRC_WIN->generic.content;
      struct symtab_and_line cursal = get_current_source_symtab_and_line ();

      if (cursal.symtab == (struct symtab *) NULL)
	s = find_pc_symtab (get_frame_pc (deprecated_selected_frame));
      else
	s = cursal.symtab;

      if (scroll_direction == FORWARD_SCROLL)
	{
	  l.line_no = content[0]->which_element.source.line_or_addr.line_no +
	    num_to_scroll;
	  if (l.line_no > s->nlines)
	    /*line = s->nlines - win_info->generic.content_size + 1; */
	    /*elz: fix for dts 23398 */
	    l.line_no = content[0]->which_element.source.line_or_addr.line_no;
	}
      else
	{
	  l.line_no = content[0]->which_element.source.line_or_addr.line_no -
	    num_to_scroll;
	  if (l.line_no <= 0)
	    l.line_no = 1;
	}

      print_source_lines (s, l.line_no, l.line_no + 1, 0);
    }
}