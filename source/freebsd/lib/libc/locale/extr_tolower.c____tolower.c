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
typedef  int /*<<< orphan*/  __ct_rune_t ;

/* Variables and functions */
 int /*<<< orphan*/  ___tolower_l (int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  __get_locale () ; 

__ct_rune_t
___tolower(__ct_rune_t c)
{
	return ___tolower_l(c, __get_locale());
}