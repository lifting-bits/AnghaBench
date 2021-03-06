#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_5__   TYPE_2__ ;
typedef  struct TYPE_4__   TYPE_1__ ;

/* Type definitions */
struct TYPE_5__ {TYPE_1__* vtbl; } ;
typedef  TYPE_2__ mz_stream ;
typedef  int /*<<< orphan*/  int32_t ;
struct TYPE_4__ {int /*<<< orphan*/  (* open ) (TYPE_2__*,char const*,int /*<<< orphan*/ ) ;} ;

/* Variables and functions */
 int /*<<< orphan*/  MZ_STREAM_ERROR ; 
 int /*<<< orphan*/  stub1 (TYPE_2__*,char const*,int /*<<< orphan*/ ) ; 

int32_t mz_stream_open(void *stream, const char *path, int32_t mode)
{
    mz_stream *strm = (mz_stream *)stream;
    if (strm == NULL || strm->vtbl == NULL || strm->vtbl->open == NULL)
        return MZ_STREAM_ERROR;
    return strm->vtbl->open(strm, path, mode);
}