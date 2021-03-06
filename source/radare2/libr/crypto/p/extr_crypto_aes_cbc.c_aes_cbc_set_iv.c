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
typedef  int /*<<< orphan*/  ut8 ;
typedef  int /*<<< orphan*/  RCrypto ;

/* Variables and functions */
 int BLOCK_SIZE ; 
 int /*<<< orphan*/  iv ; 
 int iv_set ; 
 int /*<<< orphan*/  memcpy (int /*<<< orphan*/ ,int /*<<< orphan*/  const*,int) ; 

__attribute__((used)) static bool aes_cbc_set_iv(RCrypto *cry, const ut8 *iv_src, int ivlen) {
	if (ivlen != BLOCK_SIZE) {
		return false;
	}
	memcpy (iv, iv_src, BLOCK_SIZE);
	iv_set = 1;
	return true;
}