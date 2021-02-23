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

/* Variables and functions */
 int CreatedResultsDirectory ; 
 scalar_t__ EEXIST ; 
 int /*<<< orphan*/  ERROR ; 
 char* IntermediateResultsDirectory () ; 
 int /*<<< orphan*/  S_IRWXU ; 
 int /*<<< orphan*/  ereport (int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  errcode_for_file_access () ; 
 int /*<<< orphan*/  errmsg (char*,char*) ; 
 scalar_t__ errno ; 
 int mkdir (char*,int /*<<< orphan*/ ) ; 

__attribute__((used)) static char *
CreateIntermediateResultsDirectory(void)
{
	char *resultDirectory = IntermediateResultsDirectory();
	int makeOK = 0;

	if (!CreatedResultsDirectory)
	{
		makeOK = mkdir(resultDirectory, S_IRWXU);
		if (makeOK != 0)
		{
			if (errno == EEXIST)
			{
				/* someone else beat us to it, that's ok */
				return resultDirectory;
			}

			ereport(ERROR, (errcode_for_file_access(),
							errmsg("could not create intermediate results directory "
								   "\"%s\": %m",
								   resultDirectory)));
		}

		CreatedResultsDirectory = true;
	}

	return resultDirectory;
}