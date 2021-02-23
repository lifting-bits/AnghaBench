#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_2__   TYPE_1__ ;

/* Type definitions */
struct TYPE_2__ {int /*<<< orphan*/  mutex; int /*<<< orphan*/  unfair; } ;
struct aout_sys_common {TYPE_1__ lock; } ;

/* Variables and functions */
 int /*<<< orphan*/  OS_UNFAIR_LOCK_INIT ; 
 scalar_t__ likely (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  os_unfair_lock_lock ; 
 int /*<<< orphan*/  vlc_mutex_init (int /*<<< orphan*/ *) ; 

__attribute__((used)) static inline void
lock_init(struct aout_sys_common *p_sys)
{
    if (likely(os_unfair_lock_lock))
        p_sys->lock.unfair = OS_UNFAIR_LOCK_INIT;
    else
        vlc_mutex_init(&p_sys->lock.mutex);
}