#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_4__   TYPE_1__ ;

/* Type definitions */
struct TYPE_4__ {scalar_t__ subtable_length; } ;
typedef  TYPE_1__* GXV_Validator ;
typedef  scalar_t__ FT_ULong ;
typedef  scalar_t__ FT_Bytes ;

/* Variables and functions */
 scalar_t__ FT_NEXT_ULONG (scalar_t__) ; 
 int /*<<< orphan*/  GXV_LIMIT_CHECK (int) ; 
 int /*<<< orphan*/  GXV_TRACE (char*) ; 
 int /*<<< orphan*/  gxv_just_wdp_entry_validate (scalar_t__,scalar_t__,TYPE_1__*) ; 

__attribute__((used)) static void
  gxv_just_wdc_entry_validate( FT_Bytes       table,
                               FT_Bytes       limit,
                               GXV_Validator  gxvalid )
  {
    FT_Bytes  p = table;
    FT_ULong  count, i;


    GXV_LIMIT_CHECK( 4 );
    count = FT_NEXT_ULONG( p );
    for ( i = 0; i < count; i++ )
    {
      GXV_TRACE(( "validating wdc pair %d/%d\n", i + 1, count ));
      gxv_just_wdp_entry_validate( p, limit, gxvalid );
      p += gxvalid->subtable_length;
    }

    gxvalid->subtable_length = (FT_ULong)( p - table );
  }