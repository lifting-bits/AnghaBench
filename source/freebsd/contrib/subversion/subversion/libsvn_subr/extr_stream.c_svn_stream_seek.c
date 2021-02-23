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
struct TYPE_3__ {int /*<<< orphan*/  baton; int /*<<< orphan*/  (* seek_fn ) (int /*<<< orphan*/ ,int /*<<< orphan*/  const*) ;} ;
typedef  TYPE_1__ svn_stream_t ;
typedef  int /*<<< orphan*/  svn_stream_mark_t ;
typedef  int /*<<< orphan*/  svn_error_t ;

/* Variables and functions */
 int /*<<< orphan*/  SVN_ERR_STREAM_SEEK_NOT_SUPPORTED ; 
 int /*<<< orphan*/  stub1 (int /*<<< orphan*/ ,int /*<<< orphan*/  const*) ; 
 int /*<<< orphan*/ * svn_error_create (int /*<<< orphan*/ ,int /*<<< orphan*/ *,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/ * svn_error_trace (int /*<<< orphan*/ ) ; 

svn_error_t *
svn_stream_seek(svn_stream_t *stream, const svn_stream_mark_t *mark)
{
  if (stream->seek_fn == NULL)
    return svn_error_create(SVN_ERR_STREAM_SEEK_NOT_SUPPORTED, NULL, NULL);

  return svn_error_trace(stream->seek_fn(stream->baton, mark));
}