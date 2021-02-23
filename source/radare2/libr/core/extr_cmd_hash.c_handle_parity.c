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

/* Variables and functions */
 int /*<<< orphan*/  r_cons_printf (char*,int) ; 
 scalar_t__ r_hash_parity (int /*<<< orphan*/  const*,int) ; 

__attribute__((used)) static void handle_parity (const ut8 *block, int len) {
	r_cons_printf ("%d\n", r_hash_parity (block, len)?1:0);
}