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
typedef  int /*<<< orphan*/  br_sha384_context ;

/* Variables and functions */
 int /*<<< orphan*/  sha2big_out (int /*<<< orphan*/  const*,void*,int) ; 

void
br_sha384_out(const br_sha384_context *cc, void *dst)
{
	sha2big_out(cc, dst, 6);
}