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
struct gc_arena {int dummy; } ;

/* Variables and functions */
 int /*<<< orphan*/  gc_init (struct gc_arena*) ; 

__attribute__((used)) static inline struct gc_arena
gc_new(void)
{
    struct gc_arena ret;
    gc_init(&ret);
    return ret;
}