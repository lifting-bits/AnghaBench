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
 int __set_memory_enc_dec (unsigned long,int,int) ; 

int set_memory_encrypted(unsigned long addr, int numpages)
{
	return __set_memory_enc_dec(addr, numpages, true);
}