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
typedef  int /*<<< orphan*/  u8 ;
typedef  int /*<<< orphan*/  u32 ;

/* Variables and functions */
 int /*<<< orphan*/  WPA_GET_BE32 (int /*<<< orphan*/  const*) ; 
 int /*<<< orphan*/  WPA_PUT_BE32 (int /*<<< orphan*/ *,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  desfunc (int /*<<< orphan*/ *,int /*<<< orphan*/  const*) ; 

void des_block_decrypt(const u8 *crypt, const u32 *dk, u8 *plain)
{
	u32 work[2];
	work[0] = WPA_GET_BE32(crypt);
	work[1] = WPA_GET_BE32(crypt + 4);
	desfunc(work, dk);
	WPA_PUT_BE32(plain, work[0]);
	WPA_PUT_BE32(plain + 4, work[1]);
}