#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_12__   TYPE_5__ ;
typedef  struct TYPE_11__   TYPE_4__ ;
typedef  struct TYPE_10__   TYPE_3__ ;
typedef  struct TYPE_9__   TYPE_2__ ;
typedef  struct TYPE_8__   TYPE_1__ ;

/* Type definitions */
typedef  int /*<<< orphan*/  picture_t ;
struct TYPE_9__ {int /*<<< orphan*/  video; } ;
struct TYPE_8__ {scalar_t__ i_cat; } ;
struct TYPE_12__ {TYPE_4__* cbs; TYPE_2__ fmt_out; TYPE_1__ fmt_in; } ;
typedef  TYPE_5__ decoder_t ;
struct TYPE_10__ {int /*<<< orphan*/ * (* buffer_new ) (TYPE_5__*) ;} ;
struct TYPE_11__ {TYPE_3__ video; } ;

/* Variables and functions */
 scalar_t__ VIDEO_ES ; 
 int /*<<< orphan*/ * picture_NewFromFormat (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/ * stub1 (TYPE_5__*) ; 
 int /*<<< orphan*/  vlc_assert (int) ; 

picture_t *decoder_NewPicture( decoder_t *dec )
{
    vlc_assert( dec->fmt_in.i_cat == VIDEO_ES && dec->cbs != NULL );
    if (dec->cbs->video.buffer_new == NULL)
        return picture_NewFromFormat( &dec->fmt_out.video );
    return dec->cbs->video.buffer_new( dec );
}