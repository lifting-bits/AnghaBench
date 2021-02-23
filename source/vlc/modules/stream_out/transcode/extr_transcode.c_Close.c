#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_5__   TYPE_2__ ;
typedef  struct TYPE_4__   TYPE_1__ ;

/* Type definitions */
typedef  int /*<<< orphan*/  vlc_object_t ;
struct TYPE_4__ {TYPE_2__* p_sys; } ;
typedef  TYPE_1__ sout_stream_t ;
struct TYPE_5__ {int /*<<< orphan*/  lock; int /*<<< orphan*/  senc_cfg; int /*<<< orphan*/  afilters_cfg; int /*<<< orphan*/  aenc_cfg; int /*<<< orphan*/  vfilters_cfg; int /*<<< orphan*/  venc_cfg; } ;
typedef  TYPE_2__ sout_stream_sys_t ;

/* Variables and functions */
 int /*<<< orphan*/  free (TYPE_2__*) ; 
 int /*<<< orphan*/  sout_filters_config_clean (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  transcode_encoder_config_clean (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  vlc_mutex_destroy (int /*<<< orphan*/ *) ; 

__attribute__((used)) static void Close( vlc_object_t * p_this )
{
    sout_stream_t       *p_stream = (sout_stream_t*)p_this;
    sout_stream_sys_t   *p_sys = p_stream->p_sys;

    transcode_encoder_config_clean( &p_sys->venc_cfg );
    sout_filters_config_clean( &p_sys->vfilters_cfg );

    transcode_encoder_config_clean( &p_sys->aenc_cfg );
    sout_filters_config_clean( &p_sys->afilters_cfg );

    transcode_encoder_config_clean( &p_sys->senc_cfg );

    vlc_mutex_destroy( &p_sys->lock );

    free( p_sys );
}