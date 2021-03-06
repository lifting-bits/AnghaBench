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
 size_t STRING_LENGTH ; 
 size_t strlen (char*) ; 

char *appender(char *str, const char c)
{
    size_t len = strlen(str);

    if (len < STRING_LENGTH) {
        str[len + 1] = str[len];
        str[len] = c;
    }

    return str;
}