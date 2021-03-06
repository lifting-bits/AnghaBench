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
typedef  scalar_t__ u16 ;

/* Variables and functions */
 scalar_t__ MODULO (scalar_t__,scalar_t__) ; 

__attribute__((used)) static inline void index_adv(u16 *index, u16 val, u16 limit)
{
	*index = MODULO((*index + val), limit);
}