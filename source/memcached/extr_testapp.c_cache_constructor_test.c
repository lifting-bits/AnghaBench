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
typedef  scalar_t__ uint64_t ;
typedef  enum test_return { ____Placeholder_test_return } test_return ;
typedef  int /*<<< orphan*/  cache_t ;

/* Variables and functions */
 int TEST_FAIL ; 
 int TEST_PASS ; 
 int /*<<< orphan*/  assert (int /*<<< orphan*/ ) ; 
 scalar_t__* cache_alloc (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  cache_constructor ; 
 int /*<<< orphan*/ * cache_create (char*,int,int,int /*<<< orphan*/ ,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  cache_destroy (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  cache_free (int /*<<< orphan*/ *,scalar_t__*) ; 
 scalar_t__ constructor_pattern ; 

__attribute__((used)) static enum test_return cache_constructor_test(void)
{
    cache_t *cache = cache_create("test", sizeof(uint64_t), sizeof(uint64_t),
                                  cache_constructor, NULL);
    assert(cache != NULL);
    uint64_t *ptr = cache_alloc(cache);
    uint64_t pattern = *ptr;
    cache_free(cache, ptr);
    cache_destroy(cache);
    return (pattern == constructor_pattern) ? TEST_PASS : TEST_FAIL;
}