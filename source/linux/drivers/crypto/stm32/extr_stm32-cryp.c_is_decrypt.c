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
struct stm32_cryp {int dummy; } ;

/* Variables and functions */
 int /*<<< orphan*/  is_encrypt (struct stm32_cryp*) ; 

__attribute__((used)) static inline bool is_decrypt(struct stm32_cryp *cryp)
{
	return !is_encrypt(cryp);
}