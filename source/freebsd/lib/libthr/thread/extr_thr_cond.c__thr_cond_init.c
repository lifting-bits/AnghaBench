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
typedef  int /*<<< orphan*/  pthread_condattr_t ;
typedef  int /*<<< orphan*/ * pthread_cond_t ;

/* Variables and functions */
 int cond_init (int /*<<< orphan*/ **,int /*<<< orphan*/  const*) ; 

int
_thr_cond_init(pthread_cond_t * __restrict cond,
    const pthread_condattr_t * __restrict cond_attr)
{

	*cond = NULL;
	return (cond_init(cond, cond_attr));
}