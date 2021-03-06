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
typedef  int uint32_t ;
struct table_info {int /*<<< orphan*/  data; } ;
struct nhop6_basic {int dummy; } ;
struct nhop4_basic {int dummy; } ;
struct in_addr {int /*<<< orphan*/  s_addr; } ;
struct in6_addr {int dummy; } ;
typedef  int /*<<< orphan*/  in_addr_t ;

/* Variables and functions */
 int ENOENT ; 
 int fib4_lookup_nh_basic (int /*<<< orphan*/ ,struct in_addr,int /*<<< orphan*/ ,int /*<<< orphan*/ ,struct nhop4_basic*) ; 
 int fib6_lookup_nh_basic (int /*<<< orphan*/ ,struct in6_addr*,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ,struct nhop6_basic*) ; 

__attribute__((used)) static int
ta_lookup_kfib(struct table_info *ti, void *key, uint32_t keylen,
    uint32_t *val)
{
#ifdef INET
	struct nhop4_basic nh4;
	struct in_addr in;
#endif
#ifdef INET6
	struct nhop6_basic nh6;
#endif
	int error;

	error = ENOENT;
#ifdef INET
	if (keylen == 4) {
		in.s_addr = *(in_addr_t *)key;
		error = fib4_lookup_nh_basic(ti->data,
		    in, 0, 0, &nh4);
	}
#endif
#ifdef INET6
	if (keylen == 6)
		error = fib6_lookup_nh_basic(ti->data,
		    (struct in6_addr *)key, 0, 0, 0, &nh6);
#endif

	if (error != 0)
		return (0);

	*val = 0;

	return (1);
}