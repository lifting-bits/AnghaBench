#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_2__   TYPE_1__ ;

/* Type definitions */
typedef  scalar_t__ VC_CONTAINER_FOURCC_T ;
struct TYPE_2__ {scalar_t__ codec; int batch; } ;

/* Variables and functions */
 TYPE_1__* mp4_codec_mapping ; 

__attribute__((used)) static bool codec_needs_batch_mode(VC_CONTAINER_FOURCC_T codec)
{
   int i;
   for(i = 0; mp4_codec_mapping[i].codec; i++ )
      if(mp4_codec_mapping[i].codec == codec) break;
   return mp4_codec_mapping[i].batch;
}