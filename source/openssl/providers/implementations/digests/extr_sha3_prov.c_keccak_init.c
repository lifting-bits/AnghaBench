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
typedef  int /*<<< orphan*/  KECCAK1600_CTX ;

/* Variables and functions */
 int /*<<< orphan*/  sha3_reset (int /*<<< orphan*/ *) ; 

__attribute__((used)) static int keccak_init(void *vctx)
{
    /* The newctx() handles most of the ctx fixed setup. */
    sha3_reset((KECCAK1600_CTX *)vctx);
    return 1;
}