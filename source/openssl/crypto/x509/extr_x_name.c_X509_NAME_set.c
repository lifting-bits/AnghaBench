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
typedef  int /*<<< orphan*/  const X509_NAME ;

/* Variables and functions */
 int /*<<< orphan*/  const* X509_NAME_dup (int /*<<< orphan*/  const*) ; 
 int /*<<< orphan*/  X509_NAME_free (int /*<<< orphan*/  const*) ; 

int X509_NAME_set(X509_NAME **xn, const X509_NAME *name)
{
    X509_NAME *name_copy;

    if (*xn == name)
        return *xn != NULL;
    if ((name_copy = X509_NAME_dup(name)) == NULL)
        return 0;
    X509_NAME_free(*xn);
    *xn = name_copy;
    return 1;
}