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
typedef  int /*<<< orphan*/  uint64_t ;
typedef  int /*<<< orphan*/  OSSL_PARAM ;

/* Variables and functions */
 int /*<<< orphan*/  OSSL_PARAM_UNSIGNED_INTEGER ; 
 int /*<<< orphan*/  ossl_param_construct (char const*,int /*<<< orphan*/ ,int /*<<< orphan*/ *,int) ; 

OSSL_PARAM OSSL_PARAM_construct_uint64(const char *key, uint64_t *buf)
{
    return ossl_param_construct(key, OSSL_PARAM_UNSIGNED_INTEGER, buf,
                                sizeof(uint64_t));
}