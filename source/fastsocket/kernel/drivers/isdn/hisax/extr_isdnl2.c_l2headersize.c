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
struct Layer2 {int /*<<< orphan*/  flag; } ;

/* Variables and functions */
 int /*<<< orphan*/  FLG_LAPD ; 
 int /*<<< orphan*/  FLG_MOD128 ; 
 scalar_t__ test_bit (int /*<<< orphan*/ ,int /*<<< orphan*/ *) ; 

__attribute__((used)) static inline int
l2headersize(struct Layer2 *l2, int ui)
{
	return (((test_bit(FLG_MOD128, &l2->flag) && (!ui)) ? 2 : 1) +
		(test_bit(FLG_LAPD, &l2->flag) ? 2 : 1));
}