#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_6__   TYPE_2__ ;
typedef  struct TYPE_5__   TYPE_1__ ;

/* Type definitions */
struct TYPE_6__ {TYPE_1__* codec; } ;
typedef  TYPE_2__ snd_stream_t ;
struct TYPE_5__ {int (* read ) (TYPE_2__*,int,void*) ;} ;

/* Variables and functions */
 int stub1 (TYPE_2__*,int,void*) ; 

int S_CodecReadStream(snd_stream_t *stream, int bytes, void *buffer)
{
	return stream->codec->read(stream, bytes, buffer);
}