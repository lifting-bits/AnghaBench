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
typedef  int /*<<< orphan*/  dictEntry ;

/* Variables and functions */

int sortPointers(const void *a, const void *b) {
    unsigned long la, lb;

    la = (long) (*((dictEntry**)a));
    lb = (long) (*((dictEntry**)b));
    return la-lb;
}