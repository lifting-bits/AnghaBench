#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_15__   TYPE_3__ ;
typedef  struct TYPE_14__   TYPE_2__ ;
typedef  struct TYPE_13__   TYPE_1__ ;

/* Type definitions */
typedef  int uint32_t ;
typedef  int int64_t ;
struct TYPE_14__ {int duration; TYPE_1__* priv; } ;
typedef  TYPE_2__ VC_CONTAINER_T ;
typedef  int /*<<< orphan*/  VC_CONTAINER_STATUS_T ;
struct TYPE_15__ {int timescale; } ;
typedef  TYPE_3__ VC_CONTAINER_MODULE_T ;
struct TYPE_13__ {TYPE_3__* module; } ;

/* Variables and functions */
 void* MP4_READ_U32 (TYPE_2__*,char*) ; 
 int MP4_READ_U64 (TYPE_2__*,char*) ; 
 int MP4_READ_U8 (TYPE_2__*,char*) ; 
 int /*<<< orphan*/  MP4_SKIP_U16 (TYPE_2__*,char*) ; 
 int /*<<< orphan*/  MP4_SKIP_U24 (TYPE_2__*,char*) ; 
 int /*<<< orphan*/  MP4_SKIP_U32 (TYPE_2__*,char*) ; 
 int /*<<< orphan*/  MP4_SKIP_U64 (TYPE_2__*,char*) ; 
 int /*<<< orphan*/  STREAM_STATUS (TYPE_2__*) ; 

__attribute__((used)) static VC_CONTAINER_STATUS_T mp4_read_box_mvhd( VC_CONTAINER_T *p_ctx, int64_t size )
{
   VC_CONTAINER_MODULE_T *module = p_ctx->priv->module;
   uint32_t version, i;
   int64_t duration;

   version = MP4_READ_U8(p_ctx, "version");
   MP4_SKIP_U24(p_ctx, "flags");

   if(version)
   {
      MP4_SKIP_U64(p_ctx, "creation_time");
      MP4_SKIP_U64(p_ctx, "modification_time");
      module->timescale = MP4_READ_U32(p_ctx, "timescale");
      duration = MP4_READ_U64(p_ctx, "duration");
   }
   else
   {
      MP4_SKIP_U32(p_ctx, "creation_time");
      MP4_SKIP_U32(p_ctx, "modification_time");
      module->timescale = MP4_READ_U32(p_ctx, "timescale");
      duration = MP4_READ_U32(p_ctx, "duration");
   }

   if(module->timescale)
      p_ctx->duration = duration * 1000000 / module->timescale;

   MP4_SKIP_U32(p_ctx, "rate");
   MP4_SKIP_U16(p_ctx, "volume");
   MP4_SKIP_U16(p_ctx, "reserved");
   for(i = 0; i < 2; i++) MP4_SKIP_U32(p_ctx, "reserved");
   for(i = 0; i < 9; i++) MP4_SKIP_U32(p_ctx, "matrix");
   for(i = 0; i < 6; i++) MP4_SKIP_U32(p_ctx, "pre_defined");
   MP4_SKIP_U32(p_ctx, "next_track_ID");

   return STREAM_STATUS(p_ctx);
}