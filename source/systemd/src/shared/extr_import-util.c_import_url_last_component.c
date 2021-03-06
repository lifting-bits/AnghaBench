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
 int EINVAL ; 
 int ENOMEM ; 
 char* strchrnul (char const*,char) ; 
 char* strndup (char const*,int) ; 

int import_url_last_component(const char *url, char **ret) {
        const char *e, *p;
        char *s;

        e = strchrnul(url, '?');

        while (e > url && e[-1] == '/')
                e--;

        p = e;
        while (p > url && p[-1] != '/')
                p--;

        if (e <= p)
                return -EINVAL;

        s = strndup(p, e - p);
        if (!s)
                return -ENOMEM;

        *ret = s;
        return 0;
}