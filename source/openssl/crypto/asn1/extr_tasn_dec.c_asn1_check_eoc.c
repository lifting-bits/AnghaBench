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

__attribute__((used)) static int asn1_check_eoc(const unsigned char **in, long len)
{
    const unsigned char *p;

    if (len < 2)
        return 0;
    p = *in;
    if (p[0] == '\0' && p[1] == '\0') {
        *in += 2;
        return 1;
    }
    return 0;
}