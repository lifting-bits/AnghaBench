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
typedef  int /*<<< orphan*/  BIO ;

/* Variables and functions */
 int /*<<< orphan*/ * BIO_next (int /*<<< orphan*/ *) ; 
 int BIO_write (int /*<<< orphan*/ *,char const*,int) ; 
 int /*<<< orphan*/  copy_flags (int /*<<< orphan*/ *) ; 

__attribute__((used)) static int tls_dump_write(BIO *bio, const char *in, int inl)
{
    int ret;
    BIO *next = BIO_next(bio);

    ret = BIO_write(next, in, inl);
    copy_flags(bio);

    return ret;
}