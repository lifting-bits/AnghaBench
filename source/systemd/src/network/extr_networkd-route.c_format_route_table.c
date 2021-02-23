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
 char* route_table_to_string (int) ; 
 int /*<<< orphan*/  strpcpy (char**,size_t,char const*) ; 
 int /*<<< orphan*/  strpcpyf (char**,size_t,char*,int) ; 

const char *format_route_table(int table, char *buf, size_t size) {
        const char *s;
        char *p = buf;

        s = route_table_to_string(table);
        if (s)
                strpcpy(&p, size, s);
        else
                strpcpyf(&p, size, "%d", table);

        return buf;
}