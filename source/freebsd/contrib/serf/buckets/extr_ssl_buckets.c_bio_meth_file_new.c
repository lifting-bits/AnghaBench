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
typedef  int /*<<< orphan*/  BIO_METHOD ;

/* Variables and functions */
 int /*<<< orphan*/  BIO_TYPE_FILE ; 
 int /*<<< orphan*/ * BIO_meth_new (int /*<<< orphan*/ ,char*) ; 
 int /*<<< orphan*/  BIO_meth_set_create (int /*<<< orphan*/ *,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  BIO_meth_set_ctrl (int /*<<< orphan*/ *,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  BIO_meth_set_destroy (int /*<<< orphan*/ *,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  BIO_meth_set_gets (int /*<<< orphan*/ *,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  BIO_meth_set_read (int /*<<< orphan*/ *,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  BIO_meth_set_write (int /*<<< orphan*/ *,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  bio_bucket_create ; 
 int /*<<< orphan*/  bio_bucket_ctrl ; 
 int /*<<< orphan*/  bio_bucket_destroy ; 
 int /*<<< orphan*/  bio_file_gets ; 
 int /*<<< orphan*/  bio_file_method ; 
 int /*<<< orphan*/  bio_file_read ; 
 int /*<<< orphan*/  bio_file_write ; 

__attribute__((used)) static BIO_METHOD *bio_meth_file_new(void)
{
    BIO_METHOD *biom = NULL;

#ifdef USE_OPENSSL_1_1_API
    biom = BIO_meth_new(BIO_TYPE_FILE,
                        "Wrapper around APR file structures");
    BIO_meth_set_write(biom, bio_file_write);
    BIO_meth_set_read(biom, bio_file_read);
    BIO_meth_set_gets(biom, bio_file_gets);
    BIO_meth_set_ctrl(biom, bio_bucket_ctrl);
    BIO_meth_set_create(biom, bio_bucket_create);
    BIO_meth_set_destroy(biom, bio_bucket_destroy);
#else
    biom = &bio_file_method;
#endif

    return biom;
}