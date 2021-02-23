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
typedef  int /*<<< orphan*/  SSL_SESSION ;
typedef  int /*<<< orphan*/  BIO ;

/* Variables and functions */
 int /*<<< orphan*/  BIO_free (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/ * BIO_new_file (char const*,char*) ; 
 int /*<<< orphan*/  BIO_printf (int /*<<< orphan*/ ,char*,char const*) ; 
 int /*<<< orphan*/  ERR_print_errors (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/ * PEM_read_bio_SSL_SESSION (int /*<<< orphan*/ *,int /*<<< orphan*/ *,int /*<<< orphan*/ ,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  bio_err ; 

__attribute__((used)) static SSL_SESSION *read_session(const char *filename)
{
    SSL_SESSION *sess;
    BIO *f = BIO_new_file(filename, "r");

    if (f == NULL) {
        BIO_printf(bio_err, "Can't open session file %s\n", filename);
        ERR_print_errors(bio_err);
        return NULL;
    }
    sess = PEM_read_bio_SSL_SESSION(f, NULL, 0, NULL);
    if (sess == NULL) {
        BIO_printf(bio_err, "Can't parse session file %s\n", filename);
        ERR_print_errors(bio_err);
    }
    BIO_free(f);
    return sess;
}