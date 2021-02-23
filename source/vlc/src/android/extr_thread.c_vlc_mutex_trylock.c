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
typedef  int /*<<< orphan*/  vlc_mutex_t ;

/* Variables and functions */
 int EBUSY ; 
 int /*<<< orphan*/  VLC_THREAD_ASSERT (char*) ; 
 int pthread_mutex_trylock (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  vlc_mutex_mark (int /*<<< orphan*/ *) ; 

int vlc_mutex_trylock (vlc_mutex_t *p_mutex)
{
    int val = pthread_mutex_trylock( p_mutex );

    if (val != EBUSY) {
        VLC_THREAD_ASSERT ("locking mutex");
        vlc_mutex_mark(p_mutex);
    }
    return val;
}