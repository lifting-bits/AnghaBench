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
typedef  int uint8_t ;
typedef  int /*<<< orphan*/  eia608_t ;
typedef  int /*<<< orphan*/  eia608_status_t ;

/* Variables and functions */
 int /*<<< orphan*/  EIA608_STATUS_CHANGED ; 
 int /*<<< orphan*/  Eia608Write (int /*<<< orphan*/ *,int const) ; 
 int /*<<< orphan*/  assert (int) ; 

__attribute__((used)) static eia608_status_t Eia608ParseSingle( eia608_t *h, const uint8_t dx )
{
    assert( dx >= 0x20 );
    Eia608Write( h, dx );
    return EIA608_STATUS_CHANGED;
}