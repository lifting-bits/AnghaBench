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
typedef  int /*<<< orphan*/  uint8_t ;
struct AVAESCTR {scalar_t__ block_offset; scalar_t__ counter; } ;

/* Variables and functions */
 scalar_t__ AES_CTR_IV_SIZE ; 
 int /*<<< orphan*/  memcpy (scalar_t__,int /*<<< orphan*/  const*,scalar_t__) ; 
 int /*<<< orphan*/  memset (scalar_t__,int /*<<< orphan*/ ,scalar_t__) ; 

void av_aes_ctr_set_iv(struct AVAESCTR *a, const uint8_t* iv)
{
    memcpy(a->counter, iv, AES_CTR_IV_SIZE);
    memset(a->counter + AES_CTR_IV_SIZE, 0, sizeof(a->counter) - AES_CTR_IV_SIZE);
    a->block_offset = 0;
}