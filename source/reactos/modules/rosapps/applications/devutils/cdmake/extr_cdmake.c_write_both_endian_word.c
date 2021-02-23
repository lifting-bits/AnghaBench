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
typedef  int /*<<< orphan*/  WORD ;

/* Variables and functions */
 int /*<<< orphan*/  write_big_endian_word (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  write_little_endian_word (int /*<<< orphan*/ ) ; 

__attribute__((used)) static void write_both_endian_word(WORD x)
{
    write_little_endian_word(x);
    write_big_endian_word(x);
}