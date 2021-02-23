#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_6__   TYPE_2__ ;
typedef  struct TYPE_5__   TYPE_1__ ;

/* Type definitions */
struct TYPE_5__ {int /*<<< orphan*/  fileCompat; } ;
typedef  TYPE_1__ TaskFileDestReceiver ;
struct TYPE_6__ {int /*<<< orphan*/  len; int /*<<< orphan*/  data; } ;
typedef  TYPE_2__* StringInfo ;

/* Variables and functions */
 int /*<<< orphan*/  ERROR ; 
 int FileWriteCompat (int /*<<< orphan*/ *,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  PG_WAIT_IO ; 
 int /*<<< orphan*/  ereport (int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  errcode_for_file_access () ; 
 int /*<<< orphan*/  errmsg (char*) ; 

__attribute__((used)) static void
WriteToLocalFile(StringInfo copyData, TaskFileDestReceiver *taskFileDest)
{
	int bytesWritten = FileWriteCompat(&taskFileDest->fileCompat, copyData->data,
									   copyData->len, PG_WAIT_IO);
	if (bytesWritten < 0)
	{
		ereport(ERROR, (errcode_for_file_access(),
						errmsg("could not append to file: %m")));
	}
}