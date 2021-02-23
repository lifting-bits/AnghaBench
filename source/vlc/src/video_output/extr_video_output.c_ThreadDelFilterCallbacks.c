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
typedef  int /*<<< orphan*/  vlc_object_t ;
typedef  int /*<<< orphan*/  filter_t ;

/* Variables and functions */
 int /*<<< orphan*/  FilterRestartCallback ; 
 int VLC_SUCCESS ; 
 int /*<<< orphan*/  filter_DelProxyCallbacks (int /*<<< orphan*/ *,int /*<<< orphan*/ *,int /*<<< orphan*/ ) ; 

__attribute__((used)) static int ThreadDelFilterCallbacks(filter_t *filter, void *opaque)
{
    filter_DelProxyCallbacks((vlc_object_t *)opaque, filter,
                             FilterRestartCallback);
    return VLC_SUCCESS;
}