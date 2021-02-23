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
struct TYPE_2__ {int /*<<< orphan*/  array; } ;
struct ftl_stream {int /*<<< orphan*/  connecting; int /*<<< orphan*/  connect_thread; TYPE_1__ path; int /*<<< orphan*/  output; } ;

/* Variables and functions */
 int /*<<< orphan*/  LOG_WARNING ; 
 int OBS_OUTPUT_SUCCESS ; 
 int /*<<< orphan*/  blog (int /*<<< orphan*/ ,char*) ; 
 int /*<<< orphan*/  info (char*,int /*<<< orphan*/ ,int) ; 
 int init_connect (struct ftl_stream*) ; 
 int /*<<< orphan*/  obs_output_signal_stop (int /*<<< orphan*/ ,int) ; 
 int /*<<< orphan*/  os_atomic_set_bool (int /*<<< orphan*/ *,int) ; 
 int /*<<< orphan*/  os_set_thread_name (char*) ; 
 int /*<<< orphan*/  pthread_detach (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  stopping (struct ftl_stream*) ; 
 int try_connect (struct ftl_stream*) ; 

__attribute__((used)) static void *connect_thread(void *data)
{
	struct ftl_stream *stream = data;
	int ret;

	os_set_thread_name("ftl-stream: connect_thread");

	blog(LOG_WARNING, "ftl-stream: connect thread");

	ret = init_connect(stream);
	if (ret != OBS_OUTPUT_SUCCESS) {
		obs_output_signal_stop(stream->output, ret);
		return NULL;
	}

	ret = try_connect(stream);
	if (ret != OBS_OUTPUT_SUCCESS) {
		obs_output_signal_stop(stream->output, ret);
		info("Connection to %s failed: %d", stream->path.array, ret);
	}

	if (!stopping(stream))
		pthread_detach(stream->connect_thread);

	os_atomic_set_bool(&stream->connecting, false);
	return NULL;
}