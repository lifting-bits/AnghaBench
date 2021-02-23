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
typedef  int /*<<< orphan*/  OPENSSL_STRING ;

/* Variables and functions */
 int /*<<< orphan*/  OPENSSL_free (char*) ; 

__attribute__((used)) static void exts_cleanup(OPENSSL_STRING *x)
{
    OPENSSL_free((char *)x);
}