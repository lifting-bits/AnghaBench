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
typedef  int /*<<< orphan*/  msg ;
typedef  int /*<<< orphan*/  RETSIGTYPE ;

/* Variables and functions */
 int /*<<< orphan*/  O_WRONLY ; 
 int /*<<< orphan*/  _exit (int) ; 
 int /*<<< orphan*/  close (int) ; 
 char* current_state ; 
 char* current_test ; 
 int open (char*,int /*<<< orphan*/ ,int) ; 
 int strlen (char*) ; 
 int /*<<< orphan*/  write (int,char*,int) ; 

__attribute__((used)) static RETSIGTYPE
segv_handler(int sig)
{
    int fd;
    char msg[] = "SIGSEGV i current test: ";

    fd = open("/dev/stdout", O_WRONLY, 0600);
    if (fd >= 0) {
	write(fd, msg, sizeof(msg));
	write(fd, current_test, strlen(current_test));
	write(fd, " ", 1);
	write(fd, current_state, strlen(current_state));
	write(fd, "\n", 1);
	close(fd);
    }
    _exit(1);
}