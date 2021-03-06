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
 int MAL_MAX_TX_SIZE ; 

__attribute__((used)) static inline int mal_tx_chunks(int len)
{
	return (len + MAL_MAX_TX_SIZE - 1) / MAL_MAX_TX_SIZE;
}