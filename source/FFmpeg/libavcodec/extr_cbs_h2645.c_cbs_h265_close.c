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
struct TYPE_7__ {TYPE_2__* priv_data; } ;
struct TYPE_5__ {int /*<<< orphan*/  write_buffer; int /*<<< orphan*/  read_packet; } ;
struct TYPE_6__ {int /*<<< orphan*/ * pps_ref; int /*<<< orphan*/  pps; int /*<<< orphan*/ * sps_ref; int /*<<< orphan*/  sps; int /*<<< orphan*/ * vps_ref; int /*<<< orphan*/  vps; TYPE_1__ common; } ;
typedef  TYPE_2__ CodedBitstreamH265Context ;
typedef  TYPE_3__ CodedBitstreamContext ;

/* Variables and functions */
 int FF_ARRAY_ELEMS (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  av_buffer_unref (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  av_freep (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  ff_h2645_packet_uninit (int /*<<< orphan*/ *) ; 

__attribute__((used)) static void cbs_h265_close(CodedBitstreamContext *ctx)
{
    CodedBitstreamH265Context *h265 = ctx->priv_data;
    int i;

    ff_h2645_packet_uninit(&h265->common.read_packet);

    av_freep(&h265->common.write_buffer);

    for (i = 0; i < FF_ARRAY_ELEMS(h265->vps); i++)
        av_buffer_unref(&h265->vps_ref[i]);
    for (i = 0; i < FF_ARRAY_ELEMS(h265->sps); i++)
        av_buffer_unref(&h265->sps_ref[i]);
    for (i = 0; i < FF_ARRAY_ELEMS(h265->pps); i++)
        av_buffer_unref(&h265->pps_ref[i]);
}