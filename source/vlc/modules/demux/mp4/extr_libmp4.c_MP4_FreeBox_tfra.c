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
struct TYPE_5__ {TYPE_2__* p_tfra; } ;
struct TYPE_7__ {TYPE_1__ data; } ;
struct TYPE_6__ {int /*<<< orphan*/  p_sample_number; int /*<<< orphan*/  p_trun_number; int /*<<< orphan*/  p_traf_number; int /*<<< orphan*/  p_moof_offset; int /*<<< orphan*/  p_time; } ;
typedef  TYPE_3__ MP4_Box_t ;

/* Variables and functions */
 int /*<<< orphan*/  free (int /*<<< orphan*/ ) ; 

__attribute__((used)) static void MP4_FreeBox_tfra( MP4_Box_t *p_box )
{
    free( p_box->data.p_tfra->p_time );
    free( p_box->data.p_tfra->p_moof_offset );
    free( p_box->data.p_tfra->p_traf_number );
    free( p_box->data.p_tfra->p_trun_number );
    free( p_box->data.p_tfra->p_sample_number );
}