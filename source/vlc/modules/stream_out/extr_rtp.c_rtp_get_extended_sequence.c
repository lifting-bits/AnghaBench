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
typedef  int uint16_t ;
struct TYPE_3__ {int i_sequence; } ;
typedef  TYPE_1__ sout_stream_id_sys_t ;

/* Variables and functions */

uint16_t rtp_get_extended_sequence( sout_stream_id_sys_t *id )
{
    return id->i_sequence >> 16;
}