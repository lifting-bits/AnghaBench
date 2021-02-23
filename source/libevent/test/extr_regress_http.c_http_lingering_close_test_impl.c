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
struct evhttp_request {int dummy; } ;
typedef  struct evhttp_request evhttp_connection ;
struct evhttp {int dummy; } ;
struct basic_test_data {int /*<<< orphan*/  base; } ;
typedef  int /*<<< orphan*/  ev_uint16_t ;

/* Variables and functions */
 int /*<<< orphan*/  EVHTTP_REQ_POST ; 
 int /*<<< orphan*/  EVHTTP_SERVER_LINGERING_CLOSE ; 
 int /*<<< orphan*/  evbuffer_add_printf (int /*<<< orphan*/ ,char*,char*) ; 
 int /*<<< orphan*/  event_base_dispatch (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  evhttp_add_header (int /*<<< orphan*/ ,char*,char*) ; 
 struct evhttp_request* evhttp_connection_base_new (int /*<<< orphan*/ ,int /*<<< orphan*/ *,char*,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  evhttp_connection_free (struct evhttp_request*) ; 
 int /*<<< orphan*/  evhttp_connection_set_local_address (struct evhttp_request*,char*) ; 
 int /*<<< orphan*/  evhttp_free (struct evhttp*) ; 
 int evhttp_make_request (struct evhttp_request*,struct evhttp_request*,int /*<<< orphan*/ ,char*) ; 
 int /*<<< orphan*/  evhttp_request_get_output_buffer (struct evhttp_request*) ; 
 int /*<<< orphan*/  evhttp_request_get_output_headers (struct evhttp_request*) ; 
 struct evhttp_request* evhttp_request_new (void (*) (struct evhttp_request*,void*),int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  evhttp_set_flags (struct evhttp*,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  evhttp_set_max_body_size (struct evhttp*,size_t) ; 
 int /*<<< orphan*/  free (char*) ; 
 void http_failed_request_done (struct evhttp_request*,void*) ; 
 void http_large_entity_test_done (struct evhttp_request*,void*) ; 
 struct evhttp* http_setup (int /*<<< orphan*/ *,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 char* malloc (size_t) ; 
 int /*<<< orphan*/  memset (char*,char,size_t) ; 
 int test_ok ; 
 int /*<<< orphan*/  tt_abort_msg (char*) ; 
 int /*<<< orphan*/  tt_assert (int) ; 

__attribute__((used)) static void
http_lingering_close_test_impl(void *arg, int lingering)
{
	struct basic_test_data *data = arg;
	ev_uint16_t port = 0;
	struct evhttp_connection *evcon = NULL;
	struct evhttp_request *req = NULL;
	char *long_str = NULL;
	size_t size = (1<<20) * 3;
	void (*cb)(struct evhttp_request *, void *);
	struct evhttp *http = http_setup(&port, data->base, 0);

	test_ok = 0;

	if (lingering)
		tt_assert(!evhttp_set_flags(http, EVHTTP_SERVER_LINGERING_CLOSE));
	evhttp_set_max_body_size(http, size / 2);

	evcon = evhttp_connection_base_new(data->base, NULL, "127.0.0.1", port);
	tt_assert(evcon);
	evhttp_connection_set_local_address(evcon, "127.0.0.1");

	/*
	 * At this point, we want to schedule an HTTP GET request
	 * server using our make request method.
	 */

	long_str = malloc(size);
	memset(long_str, 'a', size);
	long_str[size - 1] = '\0';

	if (lingering)
		cb = http_large_entity_test_done;
	else
		cb = http_failed_request_done;
	req = evhttp_request_new(cb, data->base);
	tt_assert(req);
	evhttp_add_header(evhttp_request_get_output_headers(req), "Host", "somehost");
	evbuffer_add_printf(evhttp_request_get_output_buffer(req), "%s", long_str);
	if (evhttp_make_request(evcon, req, EVHTTP_REQ_POST, "/") == -1) {
		tt_abort_msg("Couldn't make request");
	}
	event_base_dispatch(data->base);

	test_ok = 1;
 end:
	if (evcon)
		evhttp_connection_free(evcon);
	if (http)
		evhttp_free(http);
	if (long_str)
		free(long_str);
}