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
 int maccalc_do_logical (int,char const**,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  op_xor ; 

__attribute__((used)) static int maccalc_do_xor(int argc, const char *argv[])
{
	return maccalc_do_logical(argc, argv, op_xor);
}