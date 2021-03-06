#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_11__   TYPE_2__ ;
typedef  struct TYPE_10__   TYPE_1__ ;

/* Type definitions */
typedef  int /*<<< orphan*/  uint8_t ;
struct TYPE_10__ {int /*<<< orphan*/  i_program_number; } ;
typedef  TYPE_1__ en50221_capmt_info_t ;
struct TYPE_11__ {int i_selected_programs; int /*<<< orphan*/  obj; } ;
typedef  TYPE_2__ cam_t ;

/* Variables and functions */
 int /*<<< orphan*/  AOT_CA_PMT ; 
 int /*<<< orphan*/  APDUSend (TYPE_2__*,int,int /*<<< orphan*/ ,int /*<<< orphan*/ *,size_t) ; 
 int CAM_PROG_MAX ; 
 int /*<<< orphan*/ * CAPMTBuild (TYPE_2__*,int,TYPE_1__ const*,int,int,size_t*) ; 
 int /*<<< orphan*/  CAPMTFirst (TYPE_2__*,int,TYPE_1__ const*) ; 
 int /*<<< orphan*/  CAPMT_WAIT ; 
 int /*<<< orphan*/  VLC_TICK_FROM_MS (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  free (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  msg_Dbg (int /*<<< orphan*/ ,char*,int /*<<< orphan*/ ,int) ; 
 int /*<<< orphan*/  msg_Warn (int /*<<< orphan*/ ,char*,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  vlc_tick_sleep (int /*<<< orphan*/ ) ; 

__attribute__((used)) static void CAPMTAdd( cam_t * p_cam, int i_session_id,
                      const en50221_capmt_info_t *p_info )
{
    uint8_t *p_capmt;
    size_t i_capmt_size;

    if( p_cam->i_selected_programs >= CAM_PROG_MAX )
    {
        msg_Warn( p_cam->obj, "Not adding CAPMT for SID %d, too many programs",
                  p_info->i_program_number );
        return;
    }
    p_cam->i_selected_programs++;
    if( p_cam->i_selected_programs == 1 )
    {
        CAPMTFirst( p_cam, i_session_id, p_info );
        return;
    }
 
#ifdef CAPMT_WAIT
    vlc_tick_sleep( VLC_TICK_FROM_MS(CAPMT_WAIT) );
#endif
 
    msg_Dbg( p_cam->obj, "adding CAPMT for SID %d on session %d",
             p_info->i_program_number, i_session_id );

    p_capmt = CAPMTBuild( p_cam, i_session_id, p_info,
                          0x4 /* add */, 0x1 /* ok_descrambling */,
                          &i_capmt_size );
    if( p_capmt != NULL )
    {
        APDUSend( p_cam, i_session_id, AOT_CA_PMT, p_capmt, i_capmt_size );
        free( p_capmt );
    }
}