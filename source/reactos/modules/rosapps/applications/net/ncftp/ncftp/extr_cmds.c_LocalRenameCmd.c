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
typedef  int /*<<< orphan*/  CommandPtr ;
typedef  int /*<<< orphan*/  ArgvInfoPtr ;

/* Variables and functions */
 int /*<<< orphan*/  ARGSUSED (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  Sys (int const,char const** const,int /*<<< orphan*/  const,char*,int) ; 
 int /*<<< orphan*/  gUnusedArg ; 
 int /*<<< orphan*/  perror (char*) ; 
 scalar_t__ rename (char const*,char const*) ; 

void
LocalRenameCmd(const int argc, const char **const argv, const CommandPtr cmdp, const ArgvInfoPtr aip)
{
#if defined(WIN32) || defined(_WINDOWS)
	if (rename(argv[1], argv[2]) < 0) {
		perror("rename");
	}
#else
	ARGSUSED(gUnusedArg);
	Sys(argc, argv, aip, "/bin/mv", 1);
#endif
}