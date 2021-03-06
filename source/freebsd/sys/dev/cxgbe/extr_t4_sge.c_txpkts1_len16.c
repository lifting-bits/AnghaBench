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
typedef  int u_int ;
struct ulptx_sgl {int dummy; } ;
struct cpl_tx_pkt_core {int dummy; } ;

/* Variables and functions */
 int howmany (int,int) ; 

__attribute__((used)) static inline u_int
txpkts1_len16(void)
{
	u_int n;

	n = sizeof(struct cpl_tx_pkt_core) + sizeof(struct ulptx_sgl);

	return (howmany(n, 16));
}