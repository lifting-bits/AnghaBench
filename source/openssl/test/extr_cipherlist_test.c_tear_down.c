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
struct TYPE_4__ {int /*<<< orphan*/ * client; int /*<<< orphan*/ * server; } ;
typedef  TYPE_1__ CIPHERLIST_TEST_FIXTURE ;

/* Variables and functions */
 int /*<<< orphan*/  OPENSSL_free (TYPE_1__*) ; 
 int /*<<< orphan*/  SSL_CTX_free (int /*<<< orphan*/ *) ; 

__attribute__((used)) static void tear_down(CIPHERLIST_TEST_FIXTURE *fixture)
{
    if (fixture != NULL) {
        SSL_CTX_free(fixture->server);
        SSL_CTX_free(fixture->client);
        fixture->server = fixture->client = NULL;
        OPENSSL_free(fixture);
    }
}