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
typedef  int /*<<< orphan*/  heim_ia5_string ;

/* Variables and functions */
 int der_get_printable_string (unsigned char const*,size_t,int /*<<< orphan*/ *,size_t*) ; 

int
der_get_ia5_string(const unsigned char *p, size_t len,
		   heim_ia5_string *str, size_t *size)
{
    return der_get_printable_string(p, len, str, size);
}