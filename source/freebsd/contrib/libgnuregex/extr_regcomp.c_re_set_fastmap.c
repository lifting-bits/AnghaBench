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
 size_t tolower (int) ; 

__attribute__((used)) static inline void
__attribute ((always_inline))
re_set_fastmap (char *fastmap, int icase, int ch)
{
  fastmap[ch] = 1;
  if (icase)
    fastmap[tolower (ch)] = 1;
}