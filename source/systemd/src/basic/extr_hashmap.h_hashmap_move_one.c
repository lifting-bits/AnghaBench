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
typedef  int /*<<< orphan*/  Hashmap ;

/* Variables and functions */
 int /*<<< orphan*/  HASHMAP_BASE (int /*<<< orphan*/ *) ; 
 int internal_hashmap_move_one (int /*<<< orphan*/ ,int /*<<< orphan*/ ,void const*) ; 

__attribute__((used)) static inline int hashmap_move_one(Hashmap *h, Hashmap *other, const void *key) {
        return internal_hashmap_move_one(HASHMAP_BASE(h), HASHMAP_BASE(other), key);
}