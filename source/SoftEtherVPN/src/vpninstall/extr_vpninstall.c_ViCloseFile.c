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
struct TYPE_4__ {int InternetFile; int /*<<< orphan*/  hInternet; int /*<<< orphan*/  hHttpFile; int /*<<< orphan*/  io; } ;
typedef  TYPE_1__ VI_FILE ;

/* Variables and functions */
 int /*<<< orphan*/  FileClose (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  Free (TYPE_1__*) ; 
 int /*<<< orphan*/  InternetCloseHandle (int /*<<< orphan*/ ) ; 

void ViCloseFile(VI_FILE *f)
{
	// Validate arguments
	if (f == NULL)
	{
		return;
	}

	if (f->InternetFile == false)
	{
		FileClose(f->io);
	}
	else
	{
		InternetCloseHandle(f->hHttpFile);
		InternetCloseHandle(f->hInternet);
	}

	Free(f);
}