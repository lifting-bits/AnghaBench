#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_4__   TYPE_1__ ;

/* Type definitions */
struct TYPE_4__ {int /*<<< orphan*/  bCaretAtEnd; } ;
typedef  TYPE_1__ ME_TextEditor ;
typedef  int /*<<< orphan*/  ME_Cursor ;

/* Variables and functions */
 int /*<<< orphan*/  FALSE ; 
 int /*<<< orphan*/  ME_SetCursorToStart (TYPE_1__*,int /*<<< orphan*/ *) ; 

__attribute__((used)) static void ME_ArrowCtrlHome(ME_TextEditor *editor, ME_Cursor *pCursor)
{
  ME_SetCursorToStart(editor, pCursor);
  editor->bCaretAtEnd = FALSE;
}