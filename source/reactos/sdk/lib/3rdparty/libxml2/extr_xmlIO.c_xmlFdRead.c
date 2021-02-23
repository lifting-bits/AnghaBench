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
typedef  scalar_t__ ptrdiff_t ;

/* Variables and functions */
 int read (int,char*,int) ; 
 int /*<<< orphan*/  xmlIOErr (int /*<<< orphan*/ ,char*) ; 

__attribute__((used)) static int
xmlFdRead (void * context, char * buffer, int len) {
    int ret;

    ret = read((int) (ptrdiff_t) context, &buffer[0], len);
    if (ret < 0) xmlIOErr(0, "read()");
    return(ret);
}