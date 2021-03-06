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
union unaligned {int s2; } ;

/* Variables and functions */

__attribute__((used)) static inline int
read_2s (const void *p) { const union unaligned *up = p; return up->s2; }