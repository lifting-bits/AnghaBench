#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_7__   TYPE_3__ ;
typedef  struct TYPE_6__   TYPE_2__ ;
typedef  struct TYPE_5__   TYPE_1__ ;

/* Type definitions */
struct TYPE_7__ {int /*<<< orphan*/  psz_item_uri_type; int /*<<< orphan*/  psz_item_name; int /*<<< orphan*/  psz_content_type; int /*<<< orphan*/  psz_content_encoding; } ;
struct TYPE_5__ {TYPE_3__* p_infe; } ;
struct TYPE_6__ {TYPE_1__ data; } ;
typedef  TYPE_2__ MP4_Box_t ;
typedef  TYPE_3__ MP4_Box_data_infe_t ;

/* Variables and functions */
 int /*<<< orphan*/  free (int /*<<< orphan*/ ) ; 

__attribute__((used)) static void MP4_FreeBox_infe( MP4_Box_t *p_box )
{
    MP4_Box_data_infe_t *p_data = p_box->data.p_infe;
    free( p_data->psz_content_encoding );
    free( p_data->psz_content_type );
    free( p_data->psz_item_name );
    free( p_data->psz_item_uri_type );
}