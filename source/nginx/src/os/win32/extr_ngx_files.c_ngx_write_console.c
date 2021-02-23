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
typedef  int /*<<< orphan*/  u_long ;
typedef  size_t ssize_t ;
typedef  int /*<<< orphan*/  ngx_fd_t ;

/* Variables and functions */
 int /*<<< orphan*/  CharToOemBuff (void*,void*,size_t) ; 
 scalar_t__ WriteFile (int /*<<< orphan*/ ,void*,size_t,int /*<<< orphan*/ *,int /*<<< orphan*/ *) ; 

ssize_t
ngx_write_console(ngx_fd_t fd, void *buf, size_t size)
{
    u_long  n;

    (void) CharToOemBuff(buf, buf, size);

    if (WriteFile(fd, buf, size, &n, NULL) != 0) {
        return (size_t) n;
    }

    return -1;
}