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
 scalar_t__ EINTR ; 
 int SIGSTOP ; 
 int /*<<< orphan*/  WUNTRACED ; 
 scalar_t__ errno ; 
 int getpid () ; 
 int /*<<< orphan*/  kill (int,int) ; 
 int sshpid ; 
 int waitpid (int,int /*<<< orphan*/ *,int /*<<< orphan*/ ) ; 

__attribute__((used)) static void
suspchild(int signo)
{
	if (sshpid > 1) {
		kill(sshpid, signo);
		while (waitpid(sshpid, NULL, WUNTRACED) == -1 && errno == EINTR)
			continue;
	}
	kill(getpid(), SIGSTOP);
}