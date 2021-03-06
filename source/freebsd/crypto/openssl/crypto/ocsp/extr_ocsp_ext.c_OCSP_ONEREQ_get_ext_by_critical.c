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
struct TYPE_3__ {int /*<<< orphan*/  singleRequestExtensions; } ;
typedef  TYPE_1__ OCSP_ONEREQ ;

/* Variables and functions */
 int X509v3_get_ext_by_critical (int /*<<< orphan*/ ,int,int) ; 

int OCSP_ONEREQ_get_ext_by_critical(OCSP_ONEREQ *x, int crit, int lastpos)
{
    return (X509v3_get_ext_by_critical
            (x->singleRequestExtensions, crit, lastpos));
}