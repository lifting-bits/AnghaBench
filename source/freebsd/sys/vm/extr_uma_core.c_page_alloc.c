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
typedef  int /*<<< orphan*/  vm_size_t ;
typedef  int /*<<< orphan*/  uma_zone_t ;
typedef  int /*<<< orphan*/  uint8_t ;

/* Variables and functions */
 int /*<<< orphan*/  DOMAINSET_FIXED (int) ; 
 int /*<<< orphan*/  UMA_SLAB_KERNEL ; 
 scalar_t__ kmem_malloc_domainset (int /*<<< orphan*/ ,int /*<<< orphan*/ ,int) ; 

__attribute__((used)) static void *
page_alloc(uma_zone_t zone, vm_size_t bytes, int domain, uint8_t *pflag,
    int wait)
{
	void *p;	/* Returned page */

	*pflag = UMA_SLAB_KERNEL;
	p = (void *)kmem_malloc_domainset(DOMAINSET_FIXED(domain), bytes, wait);

	return (p);
}