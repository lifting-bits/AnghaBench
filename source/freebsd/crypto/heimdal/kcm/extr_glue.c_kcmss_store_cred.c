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
typedef  int /*<<< orphan*/  krb5_error_code ;
typedef  int /*<<< orphan*/  krb5_creds ;
typedef  int /*<<< orphan*/  krb5_context ;
typedef  int /*<<< orphan*/  krb5_ccache ;
typedef  int /*<<< orphan*/  kcm_ccache ;

/* Variables and functions */
 int /*<<< orphan*/  KCMCACHE (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  KCM_ASSERT_VALID (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  kcm_ccache_store_cred_internal (int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ *,int,int /*<<< orphan*/ **) ; 

__attribute__((used)) static krb5_error_code
kcmss_store_cred(krb5_context context,
		 krb5_ccache id,
		 krb5_creds *creds)
{
    krb5_error_code ret;
    kcm_ccache c = KCMCACHE(id);
    krb5_creds *tmp;

    KCM_ASSERT_VALID(c);

    ret = kcm_ccache_store_cred_internal(context, c, creds, 1, &tmp);

    return ret;
}