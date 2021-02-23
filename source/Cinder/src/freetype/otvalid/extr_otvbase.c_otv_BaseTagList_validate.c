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
typedef  int /*<<< orphan*/  OTV_Validator ;
typedef  int FT_UInt ;
typedef  int /*<<< orphan*/  FT_Bytes ;

/* Variables and functions */
 int FT_NEXT_USHORT (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  OTV_EXIT ; 
 int /*<<< orphan*/  OTV_LIMIT_CHECK (int) ; 
 int /*<<< orphan*/  OTV_NAME_ENTER (char*) ; 
 int /*<<< orphan*/  OTV_TRACE (char*) ; 

__attribute__((used)) static void
  otv_BaseTagList_validate( FT_Bytes       table,
                            OTV_Validator  otvalid )
  {
    FT_Bytes  p = table;
    FT_UInt   BaseTagCount;


    OTV_NAME_ENTER( "BaseTagList" );

    OTV_LIMIT_CHECK( 2 );

    BaseTagCount = FT_NEXT_USHORT( p );

    OTV_TRACE(( " (BaseTagCount = %d)\n", BaseTagCount ));

    OTV_LIMIT_CHECK( BaseTagCount * 4 );          /* BaselineTag */

    OTV_EXIT;
  }