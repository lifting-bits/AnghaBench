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
typedef  int /*<<< orphan*/  krb5_principal ;
typedef  int /*<<< orphan*/  krb5_key_data ;
typedef  int /*<<< orphan*/  kadm5_ret_t ;

/* Variables and functions */
 int /*<<< orphan*/  __CALL (int /*<<< orphan*/ ,void*) ; 
 int /*<<< orphan*/  chpass_principal_with_key ; 

kadm5_ret_t
kadm5_chpass_principal_with_key(void *server_handle,
				krb5_principal princ,
				int n_key_data,
				krb5_key_data *key_data)
{
    return __CALL(chpass_principal_with_key,
		  (server_handle, princ, n_key_data, key_data));
}