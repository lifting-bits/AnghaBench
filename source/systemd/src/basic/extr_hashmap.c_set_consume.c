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
typedef  void Set ;

/* Variables and functions */
 int /*<<< orphan*/  assert (void*) ; 
 int /*<<< orphan*/  free (void*) ; 
 int set_put (void*,void*) ; 

int set_consume(Set *s, void *value) {
        int r;

        assert(s);
        assert(value);

        r = set_put(s, value);
        if (r <= 0)
                free(value);

        return r;
}