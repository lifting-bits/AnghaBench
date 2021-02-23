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
struct TYPE_3__ {scalar_t__ type; int /*<<< orphan*/  z; } ;
typedef  TYPE_1__ git_zstream ;

/* Variables and functions */
 scalar_t__ GIT_ZSTREAM_INFLATE ; 
 int /*<<< orphan*/  deflateEnd (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  inflateEnd (int /*<<< orphan*/ *) ; 

void git_zstream_free(git_zstream *zstream)
{
	if (zstream->type == GIT_ZSTREAM_INFLATE)
		inflateEnd(&zstream->z);
	else
		deflateEnd(&zstream->z);
}