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
struct TYPE_4__ {int /*<<< orphan*/  version; } ;
struct TYPE_5__ {TYPE_1__ cert_info; } ;
typedef  TYPE_2__ X509 ;

/* Variables and functions */
 long ASN1_INTEGER_get (int /*<<< orphan*/ ) ; 

long X509_get_version(const X509 *x)
{
    return ASN1_INTEGER_get(x->cert_info.version);
}