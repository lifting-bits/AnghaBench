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

/* Variables and functions */
 int unbase64mem_full (char const*,size_t,int,void**,size_t*) ; 

__attribute__((used)) static inline int unbase64mem(const char *p, size_t l, void **mem, size_t *len) {
        return unbase64mem_full(p, l, false, mem, len);
}