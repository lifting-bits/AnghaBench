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
typedef  int /*<<< orphan*/  uint32_t ;
typedef  int /*<<< orphan*/  krb5_storage ;
typedef  int /*<<< orphan*/  kadm5_ret_t ;
typedef  int /*<<< orphan*/  kadm5_principal_ent_t ;

/* Variables and functions */
 int /*<<< orphan*/  krb5_store_int32 (int /*<<< orphan*/ *,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  store_principal_ent (int /*<<< orphan*/ *,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 

kadm5_ret_t
kadm5_store_principal_ent_mask(krb5_storage *sp,
			       kadm5_principal_ent_t princ,
			       uint32_t mask)
{
    krb5_store_int32(sp, mask);
    return store_principal_ent (sp, princ, mask);
}