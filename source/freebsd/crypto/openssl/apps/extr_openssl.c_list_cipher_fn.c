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
typedef  int /*<<< orphan*/  EVP_CIPHER ;

/* Variables and functions */
 int /*<<< orphan*/  BIO_printf (void*,char*,char const*,...) ; 
 int /*<<< orphan*/  EVP_CIPHER_name (int /*<<< orphan*/  const*) ; 

__attribute__((used)) static void list_cipher_fn(const EVP_CIPHER *c,
                           const char *from, const char *to, void *arg)
{
    if (c != NULL) {
        BIO_printf(arg, "%s\n", EVP_CIPHER_name(c));
    } else {
        if (from == NULL)
            from = "<undefined>";
        if (to == NULL)
            to = "<undefined>";
        BIO_printf(arg, "%s => %s\n", from, to);
    }
}