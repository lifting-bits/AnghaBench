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
typedef  int /*<<< orphan*/  t ;
struct drbg_kat_pr_false {int /*<<< orphan*/  retbytes; int /*<<< orphan*/  addin2; int /*<<< orphan*/  addin1; int /*<<< orphan*/  addinreseed; int /*<<< orphan*/  entropyinreseed; int /*<<< orphan*/  persstr; int /*<<< orphan*/  nonce; int /*<<< orphan*/  entropyin; } ;
struct drbg_kat {int flags; int /*<<< orphan*/  retbyteslen; int /*<<< orphan*/  addinlen; int /*<<< orphan*/  entropyinlen; int /*<<< orphan*/  persstrlen; int /*<<< orphan*/  noncelen; int /*<<< orphan*/  nid; scalar_t__ t; } ;
struct TYPE_4__ {int /*<<< orphan*/  entropylen; int /*<<< orphan*/  entropy; int /*<<< orphan*/  noncelen; int /*<<< orphan*/  nonce; } ;
typedef  TYPE_1__ TEST_CTX ;
typedef  int /*<<< orphan*/  RAND_DRBG ;

/* Variables and functions */
 int /*<<< orphan*/  OPENSSL_free (unsigned char*) ; 
 unsigned char* OPENSSL_malloc (int /*<<< orphan*/ ) ; 
 unsigned int RAND_DRBG_FLAG_CTR_NO_DF ; 
 unsigned int RAND_DRBG_FLAG_HMAC ; 
 int /*<<< orphan*/  RAND_DRBG_free (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  RAND_DRBG_generate (int /*<<< orphan*/ *,unsigned char*,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  RAND_DRBG_instantiate (int /*<<< orphan*/ *,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/ * RAND_DRBG_new (int /*<<< orphan*/ ,unsigned int,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  RAND_DRBG_reseed (int /*<<< orphan*/ *,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  RAND_DRBG_set_callbacks (int /*<<< orphan*/ *,int /*<<< orphan*/ ,int /*<<< orphan*/ *,int /*<<< orphan*/ ,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  RAND_DRBG_set_ex_data (int /*<<< orphan*/ *,int /*<<< orphan*/ ,TYPE_1__*) ; 
 int /*<<< orphan*/  RAND_DRBG_uninstantiate (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  TEST_mem_eq (int /*<<< orphan*/ ,int /*<<< orphan*/ ,unsigned char*,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  TEST_ptr (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  TEST_true (int /*<<< orphan*/ ) ; 
 int USE_DF ; 
 int USE_HMAC ; 
 int /*<<< orphan*/  app_data_index ; 
 int /*<<< orphan*/  kat_entropy ; 
 int /*<<< orphan*/  kat_nonce ; 
 int /*<<< orphan*/  memset (TYPE_1__*,int /*<<< orphan*/ ,int) ; 

__attribute__((used)) static int single_kat_pr_false(const struct drbg_kat *td)
{
    struct drbg_kat_pr_false *data = (struct drbg_kat_pr_false *)td->t;
    RAND_DRBG *drbg = NULL;
    unsigned char *buff = NULL;
    unsigned int flags = 0;
    int failures = 0;
    TEST_CTX t;

    if ((td->flags & USE_DF) == 0)
        flags |= RAND_DRBG_FLAG_CTR_NO_DF;
    if ((td->flags & USE_HMAC) != 0)
        flags |= RAND_DRBG_FLAG_HMAC;

    if (!TEST_ptr(drbg = RAND_DRBG_new(td->nid, flags, NULL)))
        return 0;

    if (!TEST_true(RAND_DRBG_set_callbacks(drbg, kat_entropy, NULL,
                                           kat_nonce, NULL))) {
        failures++;
        goto err;
    }
    memset(&t, 0, sizeof(t));
    t.entropy = data->entropyin;
    t.entropylen = td->entropyinlen;
    t.nonce = data->nonce;
    t.noncelen = td->noncelen;
    RAND_DRBG_set_ex_data(drbg, app_data_index, &t);

    buff = OPENSSL_malloc(td->retbyteslen);
    if (buff == NULL)
        goto err;

    if (!TEST_true(RAND_DRBG_instantiate(drbg, data->persstr, td->persstrlen)))
        failures++;

    t.entropy = data->entropyinreseed;
    t.entropylen = td->entropyinlen;

    if (!TEST_true(RAND_DRBG_reseed(drbg, data->addinreseed, td->addinlen, 0))
        || !TEST_true(RAND_DRBG_generate(drbg, buff, td->retbyteslen, 0,
                                         data->addin1, td->addinlen))
        || !TEST_true(RAND_DRBG_generate(drbg, buff, td->retbyteslen, 0,
                                         data->addin2, td->addinlen))
        || !TEST_true(RAND_DRBG_uninstantiate(drbg))
        || !TEST_mem_eq(data->retbytes, td->retbyteslen, buff,
                        td->retbyteslen))
        failures++;

err:
    OPENSSL_free(buff);
    RAND_DRBG_uninstantiate(drbg);
    RAND_DRBG_free(drbg);
    return failures == 0;
}