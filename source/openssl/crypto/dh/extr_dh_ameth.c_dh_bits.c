#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_7__   TYPE_3__ ;
typedef  struct TYPE_6__   TYPE_2__ ;
typedef  struct TYPE_5__   TYPE_1__ ;

/* Type definitions */
struct TYPE_6__ {TYPE_1__* dh; } ;
struct TYPE_7__ {TYPE_2__ pkey; } ;
struct TYPE_5__ {int /*<<< orphan*/  p; } ;
typedef  TYPE_3__ EVP_PKEY ;

/* Variables and functions */
 int BN_num_bits (int /*<<< orphan*/ ) ; 

__attribute__((used)) static int dh_bits(const EVP_PKEY *pkey)
{
    return BN_num_bits(pkey->pkey.dh->p);
}