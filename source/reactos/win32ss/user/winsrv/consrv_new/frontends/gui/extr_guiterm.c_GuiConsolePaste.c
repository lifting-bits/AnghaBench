#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_3__   TYPE_1__ ;

/* Type definitions */
typedef  int /*<<< orphan*/  VOID ;
struct TYPE_3__ {int /*<<< orphan*/  Console; int /*<<< orphan*/  hWindow; } ;
typedef  int /*<<< orphan*/  PTEXTMODE_SCREEN_BUFFER ;
typedef  TYPE_1__* PGUI_CONSOLE_DATA ;
typedef  int /*<<< orphan*/  PGRAPHICS_SCREEN_BUFFER ;
typedef  scalar_t__ PCONSOLE_SCREEN_BUFFER ;
typedef  int /*<<< orphan*/  PCONSOLE ;

/* Variables and functions */
 int /*<<< orphan*/  CloseClipboard () ; 
 scalar_t__ ConDrvGetActiveScreenBuffer (int /*<<< orphan*/ ) ; 
 scalar_t__ GetType (scalar_t__) ; 
 int /*<<< orphan*/  GuiPasteToGraphicsBuffer (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  GuiPasteToTextModeBuffer (int /*<<< orphan*/ ) ; 
 scalar_t__ OpenClipboard (int /*<<< orphan*/ ) ; 
 scalar_t__ TEXTMODE_BUFFER ; 

__attribute__((used)) static VOID
GuiConsolePaste(PGUI_CONSOLE_DATA GuiData)
{
    if (OpenClipboard(GuiData->hWindow))
    {
        PCONSOLE Console = GuiData->Console;
        PCONSOLE_SCREEN_BUFFER Buffer = ConDrvGetActiveScreenBuffer(Console);

        if (GetType(Buffer) == TEXTMODE_BUFFER)
        {
            GuiPasteToTextModeBuffer((PTEXTMODE_SCREEN_BUFFER)Buffer);
        }
        else /* if (GetType(Buffer) == GRAPHICS_BUFFER) */
        {
            GuiPasteToGraphicsBuffer((PGRAPHICS_SCREEN_BUFFER)Buffer);
        }

        CloseClipboard();
    }
}