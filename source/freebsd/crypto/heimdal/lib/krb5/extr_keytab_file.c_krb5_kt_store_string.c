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
typedef  int /*<<< orphan*/  krb5_storage ;
typedef  int krb5_error_code ;
typedef  int /*<<< orphan*/  heim_general_string ;

/* Variables and functions */
 int KRB5_KT_END ; 
 int errno ; 
 int krb5_storage_write (int /*<<< orphan*/ *,int /*<<< orphan*/ ,size_t) ; 
 int krb5_store_int16 (int /*<<< orphan*/ *,size_t) ; 
 size_t strlen (int /*<<< orphan*/ ) ; 

__attribute__((used)) static krb5_error_code
krb5_kt_store_string(krb5_storage *sp,
		     heim_general_string data)
{
    int ret;
    size_t len = strlen(data);
    ret = krb5_store_int16(sp, len);
    if(ret < 0)
	return ret;
    ret = krb5_storage_write(sp, data, len);
    if(ret != (int)len){
	if(ret < 0)
	    return errno;
	return KRB5_KT_END;
    }
    return 0;
}