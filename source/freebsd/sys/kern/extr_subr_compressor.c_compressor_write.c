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
struct compressor {int /*<<< orphan*/  arg; int /*<<< orphan*/  cb; int /*<<< orphan*/  priv; TYPE_1__* methods; } ;
struct TYPE_2__ {int (* write ) (int /*<<< orphan*/ ,void*,size_t,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ;} ;

/* Variables and functions */
 int stub1 (int /*<<< orphan*/ ,void*,size_t,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 

int
compressor_write(struct compressor *stream, void *data, size_t len)
{

	return (stream->methods->write(stream->priv, data, len, stream->cb,
	    stream->arg));
}