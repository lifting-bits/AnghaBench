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
struct evhttp_connection {int dummy; } ;
struct basic_test_data {int /*<<< orphan*/  base; } ;
typedef  int /*<<< orphan*/  ev_uint16_t ;

/* Variables and functions */
 scalar_t__ BASIC_REQUEST_BODY ; 
 int /*<<< orphan*/  EVHTTP_REQ_GET ; 
 int /*<<< orphan*/  event_base_dispatch (int /*<<< orphan*/ ) ; 
 struct evhttp_connection* evhttp_connection_base_new (int /*<<< orphan*/ ,int /*<<< orphan*/ *,char*,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  evhttp_connection_free (struct evhttp_connection*) ; 
 int /*<<< orphan*/  evhttp_connection_set_closecb (struct evhttp_connection*,int /*<<< orphan*/  (*) (struct evhttp_connection*,int /*<<< orphan*/ *),void*) ; 
 int /*<<< orphan*/  evhttp_free (scalar_t__) ; 
 int evhttp_make_request (struct evhttp_connection*,struct evhttp_request*,int /*<<< orphan*/ ,char*) ; 
 struct evhttp_request* evhttp_request_new (int /*<<< orphan*/ ,void*) ; 
 int /*<<< orphan*/  exit_base ; 
 scalar_t__ http ; 
 int /*<<< orphan*/  http_request_done ; 
 int /*<<< orphan*/  http_request_get_addr_on_close (struct evhttp_connection*,int /*<<< orphan*/ *) ; 
 scalar_t__ http_setup (int /*<<< orphan*/ *,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 scalar_t__ test_ok ; 
 int /*<<< orphan*/  tt_abort_msg (char*) ; 
 int /*<<< orphan*/  tt_assert (struct evhttp_connection*) ; 

__attribute__((used)) static void
http_get_addr_test(void *arg)
{
	struct basic_test_data *data = arg;
	ev_uint16_t port = 0;
	struct evhttp_connection *evcon = NULL;
	struct evhttp_request *req = NULL;

	test_ok = 0;
	exit_base = data->base;

	http = http_setup(&port, data->base, 0);

	evcon = evhttp_connection_base_new(data->base, NULL, "127.0.0.1", port);
	tt_assert(evcon);
	evhttp_connection_set_closecb(evcon, http_request_get_addr_on_close, arg);

	/*
	 * At this point, we want to schedule a request to the HTTP
	 * server using our make request method.
	 */

	req = evhttp_request_new(http_request_done, (void *)BASIC_REQUEST_BODY);

	/* We give ownership of the request to the connection */
	if (evhttp_make_request(evcon, req, EVHTTP_REQ_GET, "/test") == -1) {
		tt_abort_msg("Couldn't make request");
	}

	event_base_dispatch(data->base);

	http_request_get_addr_on_close(evcon, NULL);

 end:
	if (evcon)
		evhttp_connection_free(evcon);
	if (http)
		evhttp_free(http);
}