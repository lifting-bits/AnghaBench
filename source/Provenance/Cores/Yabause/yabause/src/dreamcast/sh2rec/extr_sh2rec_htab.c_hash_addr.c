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
typedef  unsigned int u32 ;

/* Variables and functions */
 int SH2REC_HTAB_ENTRIES ; 

__attribute__((used)) static inline int hash_addr(u32 addr) {
    return ((addr ^ 2654435761U) >> 2) & (SH2REC_HTAB_ENTRIES - 1);
}