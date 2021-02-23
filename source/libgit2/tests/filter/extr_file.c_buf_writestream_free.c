#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */

/* Type definitions */
struct buf_writestream {int /*<<< orphan*/  buf; } ;
typedef  int /*<<< orphan*/  git_writestream ;

/* Variables and functions */
 int /*<<< orphan*/  git_buf_dispose (int /*<<< orphan*/ *) ; 

void buf_writestream_free(git_writestream *s)
{
	struct buf_writestream *stream = (struct buf_writestream *)s;
	git_buf_dispose(&stream->buf);
}