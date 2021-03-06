#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_3__   TYPE_1__ ;

/* Type definitions */
typedef  int /*<<< orphan*/  X509_ATTRIBUTE ;
struct TYPE_3__ {int /*<<< orphan*/  attributes; } ;
typedef  TYPE_1__ EVP_PKEY ;

/* Variables and functions */
 scalar_t__ X509at_add1_attr (int /*<<< orphan*/ *,int /*<<< orphan*/ *) ; 

int EVP_PKEY_add1_attr(EVP_PKEY *key, X509_ATTRIBUTE *attr)
{
    if (X509at_add1_attr(&key->attributes, attr))
        return 1;
    return 0;
}