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
typedef  scalar_t__ UINT8 ;
typedef  int /*<<< orphan*/  UINT32 ;
typedef  int /*<<< orphan*/  UINT16 ;
typedef  int /*<<< orphan*/  BOOLEAN ;

/* Variables and functions */
 int /*<<< orphan*/  BTM_EIR_HAS_SERVICE (int /*<<< orphan*/ *,scalar_t__) ; 
 scalar_t__ BTM_EIR_MAX_SERVICES ; 
 int /*<<< orphan*/  FALSE ; 
 scalar_t__ btm_convert_uuid_to_eir_service (int /*<<< orphan*/ ) ; 

BOOLEAN BTM_HasEirService( UINT32 *p_eir_uuid, UINT16 uuid16 )
{
    UINT8 service_id;

    service_id = btm_convert_uuid_to_eir_service(uuid16);
    if ( service_id < BTM_EIR_MAX_SERVICES ) {
        return ( BTM_EIR_HAS_SERVICE( p_eir_uuid, service_id ));
    } else {
        return ( FALSE );
    }
}