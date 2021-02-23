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
 int SERVER () ; 
 int /*<<< orphan*/  ckresp (int,char*) ; 
 int mustdiallocal (int) ; 
 int /*<<< orphan*/  mustsend (int,char*) ; 

void
cttest_garbage_priority()
{
    int port = SERVER();
    int fd = mustdiallocal(port);
    mustsend(fd, "put -1kkdj9djjkd9 0 100 1\r\n");
    mustsend(fd, "a\r\n");
    ckresp(fd, "BAD_FORMAT\r\n");
}