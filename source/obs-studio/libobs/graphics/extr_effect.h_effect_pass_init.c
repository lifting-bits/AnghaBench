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
struct gs_effect_pass {int dummy; } ;

/* Variables and functions */
 int /*<<< orphan*/  memset (struct gs_effect_pass*,int /*<<< orphan*/ ,int) ; 

__attribute__((used)) static inline void effect_pass_init(struct gs_effect_pass *pass)
{
	memset(pass, 0, sizeof(struct gs_effect_pass));
}