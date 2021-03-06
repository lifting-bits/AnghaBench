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
typedef  int /*<<< orphan*/  ASN1_BIT_STRING ;

/* Variables and functions */
 int ASN1_STRING_set (int /*<<< orphan*/ *,unsigned char*,int) ; 

int ASN1_BIT_STRING_set(ASN1_BIT_STRING *x, unsigned char *d, int len)
{
    return ASN1_STRING_set(x, d, len);
}