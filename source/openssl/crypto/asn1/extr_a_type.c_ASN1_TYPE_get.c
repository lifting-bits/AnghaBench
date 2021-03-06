#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_5__   TYPE_2__ ;
typedef  struct TYPE_4__   TYPE_1__ ;

/* Type definitions */
struct TYPE_4__ {int /*<<< orphan*/ * ptr; } ;
struct TYPE_5__ {scalar_t__ type; TYPE_1__ value; } ;
typedef  TYPE_2__ ASN1_TYPE ;

/* Variables and functions */
 scalar_t__ V_ASN1_BOOLEAN ; 
 scalar_t__ V_ASN1_NULL ; 

int ASN1_TYPE_get(const ASN1_TYPE *a)
{
    if (a->type == V_ASN1_BOOLEAN
            || a->type == V_ASN1_NULL
            || a->value.ptr != NULL)
        return a->type;
    else
        return 0;
}