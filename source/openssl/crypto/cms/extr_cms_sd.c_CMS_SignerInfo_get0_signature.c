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
struct TYPE_3__ {int /*<<< orphan*/ * signature; } ;
typedef  TYPE_1__ CMS_SignerInfo ;
typedef  int /*<<< orphan*/  ASN1_OCTET_STRING ;

/* Variables and functions */

ASN1_OCTET_STRING *CMS_SignerInfo_get0_signature(CMS_SignerInfo *si)
{
    return si->signature;
}