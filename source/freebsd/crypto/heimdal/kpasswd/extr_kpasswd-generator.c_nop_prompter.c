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
typedef  int /*<<< orphan*/  krb5_prompt ;
typedef  int /*<<< orphan*/  krb5_context ;

/* Variables and functions */

__attribute__((used)) static int
nop_prompter (krb5_context context,
	      void *data,
	      const char *name,
	      const char *banner,
	      int num_prompts,
	      krb5_prompt prompts[])
{
    return 0;
}