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
struct TYPE_3__ {int /*<<< orphan*/  comment; } ;
typedef  TYPE_1__ hb_metadata_t ;

/* Variables and functions */
 int /*<<< orphan*/  hb_update_str (int /*<<< orphan*/ *,char const*) ; 

void hb_metadata_set_comment( hb_metadata_t *metadata, const char *comment )
{
    if ( metadata )
    {
        hb_update_str( &metadata->comment, comment );
    }
}