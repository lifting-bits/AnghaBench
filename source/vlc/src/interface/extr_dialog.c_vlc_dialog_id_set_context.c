#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_3__   TYPE_1__ ;

/* Type definitions */
struct TYPE_3__ {int /*<<< orphan*/  lock; void* p_context; } ;
typedef  TYPE_1__ vlc_dialog_id ;

/* Variables and functions */
 int /*<<< orphan*/  vlc_mutex_lock (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  vlc_mutex_unlock (int /*<<< orphan*/ *) ; 

void
vlc_dialog_id_set_context(vlc_dialog_id *p_id, void *p_context)
{
    vlc_mutex_lock(&p_id->lock);
    p_id->p_context = p_context;
    vlc_mutex_unlock(&p_id->lock);
}