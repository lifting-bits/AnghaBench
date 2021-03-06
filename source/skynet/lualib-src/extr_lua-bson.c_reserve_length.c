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
struct bson {int size; } ;

/* Variables and functions */
 int /*<<< orphan*/  bson_reserve (struct bson*,int) ; 

__attribute__((used)) static inline int
reserve_length(struct bson *b) {
	int sz = b->size;
	bson_reserve(b,4);
	b->size +=4;
	return sz;
}