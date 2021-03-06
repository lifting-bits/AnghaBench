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
typedef  int /*<<< orphan*/  X509 ;
typedef  int /*<<< orphan*/  BIO ;

/* Variables and functions */
 int /*<<< orphan*/  PEM_write_bio_X509 (int /*<<< orphan*/ *,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  X509_print (int /*<<< orphan*/ *,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  i2d_X509_bio (int /*<<< orphan*/ *,int /*<<< orphan*/ *) ; 

__attribute__((used)) static void write_new_certificate(BIO *bp, X509 *x, int output_der, int notext)
{

    if (output_der) {
        (void)i2d_X509_bio(bp, x);
        return;
    }
    if (!notext)
        X509_print(bp, x);
    PEM_write_bio_X509(bp, x);
}