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

/* Variables and functions */
 scalar_t__ ARGON2_MAX_TIME ; 
 int /*<<< orphan*/  COMPILER_ASSERT (int) ; 
 scalar_t__ crypto_pwhash_argon2id_OPSLIMIT_MAX ; 

size_t
crypto_pwhash_argon2id_opslimit_max(void)
{
    COMPILER_ASSERT(crypto_pwhash_argon2id_OPSLIMIT_MAX <= ARGON2_MAX_TIME);
    return crypto_pwhash_argon2id_OPSLIMIT_MAX;
}