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
struct macro_param {int /*<<< orphan*/  tokens; int /*<<< orphan*/  name; } ;

/* Variables and functions */
 int /*<<< orphan*/  cf_token_clear (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  da_free (int /*<<< orphan*/ ) ; 

__attribute__((used)) static inline void macro_param_free(struct macro_param *param)
{
	cf_token_clear(&param->name);
	da_free(param->tokens);
}