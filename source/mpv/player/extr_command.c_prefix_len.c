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
 char* strchr (char const*,char) ; 
 int strlen (char const*) ; 

__attribute__((used)) static int prefix_len(const char *p)
{
    const char *end = strchr(p, '/');
    return end ? end - p : strlen(p) + 1;
}