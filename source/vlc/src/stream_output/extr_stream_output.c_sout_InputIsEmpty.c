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
struct TYPE_4__ {TYPE_2__* p_sout; } ;
typedef  TYPE_1__ sout_packetizer_input_t ;
struct TYPE_5__ {int /*<<< orphan*/  lock; int /*<<< orphan*/  p_stream; } ;
typedef  TYPE_2__ sout_instance_t ;

/* Variables and functions */
 int /*<<< orphan*/  SOUT_STREAM_EMPTY ; 
 scalar_t__ VLC_SUCCESS ; 
 scalar_t__ sout_StreamControl (int /*<<< orphan*/ ,int /*<<< orphan*/ ,int*) ; 
 int /*<<< orphan*/  vlc_mutex_lock (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  vlc_mutex_unlock (int /*<<< orphan*/ *) ; 

bool sout_InputIsEmpty( sout_packetizer_input_t *p_input )
{
    sout_instance_t *p_sout = p_input->p_sout;
    bool b;

    vlc_mutex_lock( &p_sout->lock );
    if( sout_StreamControl( p_sout->p_stream, SOUT_STREAM_EMPTY, &b ) != VLC_SUCCESS )
        b = true;
    vlc_mutex_unlock( &p_sout->lock );
    return b;
}