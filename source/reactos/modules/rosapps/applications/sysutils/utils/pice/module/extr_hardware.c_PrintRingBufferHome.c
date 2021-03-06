#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_2__   TYPE_1__ ;

/* Type definitions */
typedef  scalar_t__ ULONG ;
struct TYPE_2__ {scalar_t__ y; scalar_t__ cy; scalar_t__ usCurY; scalar_t__ usCurX; } ;
typedef  int /*<<< orphan*/  BOOLEAN ;

/* Variables and functions */
 int /*<<< orphan*/  ClrLine (scalar_t__) ; 
 int /*<<< orphan*/  DPRINT (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  FALSE ; 
 int /*<<< orphan*/  Home (size_t) ; 
 int /*<<< orphan*/  LEAVE_FUNC () ; 
 scalar_t__ LINES_IN_BUFFER ; 
 scalar_t__ LinesInRingBuffer () ; 
 size_t OUTPUT_WINDOW ; 
 int /*<<< orphan*/  OUTPUT_WINDOW_UNBUFFERED ; 
 scalar_t__ PICE_strlen (char*) ; 
 int /*<<< orphan*/  Print (int /*<<< orphan*/ ,char*) ; 
 int /*<<< orphan*/  TRUE ; 
 char** aBuffers ; 
 size_t ulInPos ; 
 scalar_t__ ulLastPos ; 
 TYPE_1__* wWindow ; 

BOOLEAN PrintRingBufferHome(ULONG ulLines)
{
	ULONG ulDelta = LinesInRingBuffer();
	ULONG ulOutPos,i=0;

//    ENTER_FUNC();

    // no lines in ring buffer
	if(!ulDelta)
    {
        DPRINT((0,"PrintRingBufferHome(): no lines in ring buffer\n"));
        LEAVE_FUNC();
		return FALSE;
    }

    // more lines inc. offset to display than in ring buffer
	if(ulDelta < ulLines)
    {
        ulLines = ulDelta;
    }

    // calc the start out position
	ulOutPos = ulLastPos;

    // start to output upper left corner of window
	Home(OUTPUT_WINDOW);

    // while not end reached...
	while(ulLines--)
	{
        ClrLine(wWindow[OUTPUT_WINDOW].y+i);
		Print(OUTPUT_WINDOW_UNBUFFERED,aBuffers[ulOutPos]);
		i++;
		ulOutPos = (ulOutPos+1)%LINES_IN_BUFFER;
	}

    if(aBuffers[ulInPos][0]==':')
    {
        ClrLine(wWindow[OUTPUT_WINDOW].y+wWindow[OUTPUT_WINDOW].cy-1);
        wWindow[OUTPUT_WINDOW].usCurY = wWindow[OUTPUT_WINDOW].cy-1;
		Print(OUTPUT_WINDOW_UNBUFFERED,aBuffers[ulInPos]);
    	wWindow[OUTPUT_WINDOW].usCurX = PICE_strlen(aBuffers[ulInPos])+1;
    }

//    LEAVE_FUNC();

    return TRUE;
}