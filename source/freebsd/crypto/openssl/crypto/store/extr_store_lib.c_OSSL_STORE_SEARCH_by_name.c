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
typedef  int /*<<< orphan*/  X509_NAME ;
struct TYPE_4__ {int /*<<< orphan*/ * name; int /*<<< orphan*/  search_type; } ;
typedef  TYPE_1__ OSSL_STORE_SEARCH ;

/* Variables and functions */
 int /*<<< orphan*/  ERR_R_MALLOC_FAILURE ; 
 TYPE_1__* OPENSSL_zalloc (int) ; 
 int /*<<< orphan*/  OSSL_STORE_F_OSSL_STORE_SEARCH_BY_NAME ; 
 int /*<<< orphan*/  OSSL_STORE_SEARCH_BY_NAME ; 
 int /*<<< orphan*/  OSSL_STOREerr (int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 

OSSL_STORE_SEARCH *OSSL_STORE_SEARCH_by_name(X509_NAME *name)
{
    OSSL_STORE_SEARCH *search = OPENSSL_zalloc(sizeof(*search));

    if (search == NULL) {
        OSSL_STOREerr(OSSL_STORE_F_OSSL_STORE_SEARCH_BY_NAME,
                      ERR_R_MALLOC_FAILURE);
        return NULL;
    }

    search->search_type = OSSL_STORE_SEARCH_BY_NAME;
    search->name = name;
    return search;
}