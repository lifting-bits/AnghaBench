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
struct TYPE_4__ {int /*<<< orphan*/  lock; int /*<<< orphan*/  global_properties; int /*<<< orphan*/  algs; } ;
typedef  TYPE_1__ OSSL_METHOD_STORE ;

/* Variables and functions */
 int /*<<< orphan*/  CRYPTO_THREAD_lock_free (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  OPENSSL_free (TYPE_1__*) ; 
 int /*<<< orphan*/  alg_cleanup ; 
 int /*<<< orphan*/  ossl_property_free (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  ossl_sa_ALGORITHM_doall (int /*<<< orphan*/ ,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  ossl_sa_ALGORITHM_free (int /*<<< orphan*/ ) ; 

void ossl_method_store_free(OSSL_METHOD_STORE *store)
{
    if (store != NULL) {
        ossl_sa_ALGORITHM_doall(store->algs, &alg_cleanup);
        ossl_sa_ALGORITHM_free(store->algs);
        ossl_property_free(store->global_properties);
        CRYPTO_THREAD_lock_free(store->lock);
        OPENSSL_free(store);
    }
}