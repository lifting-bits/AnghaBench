#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_4__   TYPE_1__ ;

/* Type definitions */
typedef  scalar_t__ uint32_t ;
typedef  int /*<<< orphan*/  krb5_storage ;
typedef  int /*<<< orphan*/  krb5_data ;
typedef  scalar_t__ kadm5_ret_t ;
struct TYPE_4__ {int /*<<< orphan*/  context; } ;
typedef  TYPE_1__ kadm5_client_context ;
typedef  scalar_t__ int32_t ;
typedef  int /*<<< orphan*/  buf ;

/* Variables and functions */
 scalar_t__ ENOMEM ; 
 scalar_t__ _kadm5_client_recv (TYPE_1__*,int /*<<< orphan*/ *) ; 
 scalar_t__ _kadm5_client_send (TYPE_1__*,int /*<<< orphan*/ *) ; 
 scalar_t__ _kadm5_connect (void*) ; 
 int /*<<< orphan*/  kadm_get_privs ; 
 int /*<<< orphan*/  krb5_clear_error_message (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  krb5_data_free (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  krb5_ret_int32 (int /*<<< orphan*/ *,scalar_t__*) ; 
 int /*<<< orphan*/  krb5_ret_uint32 (int /*<<< orphan*/ *,scalar_t__*) ; 
 int /*<<< orphan*/  krb5_storage_free (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/ * krb5_storage_from_data (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/ * krb5_storage_from_mem (unsigned char*,int) ; 
 int /*<<< orphan*/  krb5_store_int32 (int /*<<< orphan*/ *,int /*<<< orphan*/ ) ; 

kadm5_ret_t
kadm5_c_get_privs(void *server_handle, uint32_t *privs)
{
    kadm5_client_context *context = server_handle;
    kadm5_ret_t ret;
    krb5_storage *sp;
    unsigned char buf[1024];
    int32_t tmp;
    krb5_data reply;

    *privs = 0;

    ret = _kadm5_connect(server_handle);
    if(ret)
	return ret;

    sp = krb5_storage_from_mem(buf, sizeof(buf));
    if (sp == NULL) {
	krb5_clear_error_message(context->context);
	return ENOMEM;
    }
    krb5_store_int32(sp, kadm_get_privs);
    ret = _kadm5_client_send(context, sp);
    krb5_storage_free(sp);
    if(ret)
	return ret;
    ret = _kadm5_client_recv(context, &reply);
    if (ret)
	return ret;
    sp = krb5_storage_from_data(&reply);
    if (sp == NULL) {
	krb5_clear_error_message(context->context);
	krb5_data_free (&reply);
	return ENOMEM;
    }
    krb5_ret_int32(sp, &tmp);
    krb5_clear_error_message(context->context);
    ret = tmp;
    if(ret == 0){
	krb5_ret_uint32(sp, privs);
    }
    krb5_storage_free(sp);
    krb5_data_free (&reply);
    return ret;
}