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
struct evbuffer {int dummy; } ;
struct bufferevent {struct evbuffer* input; } ;

/* Variables and functions */
 int /*<<< orphan*/  EV_READ ; 
 int /*<<< orphan*/  assert (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  bufferevent_disable (struct bufferevent*,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  bufferevent_read_buffer (struct bufferevent*,struct evbuffer*) ; 
 int /*<<< orphan*/  evbuffer_free (struct evbuffer*) ; 
 int evbuffer_get_length (struct evbuffer*) ; 
 struct evbuffer* evbuffer_new () ; 
 int /*<<< orphan*/  test_ok ; 

__attribute__((used)) static void
readcb(struct bufferevent *bev, void *arg)
{
	if (evbuffer_get_length(bev->input) == 8333) {
		struct evbuffer *evbuf = evbuffer_new();
		assert(evbuf != NULL);

		/* gratuitous test of bufferevent_read_buffer */
		bufferevent_read_buffer(bev, evbuf);

		bufferevent_disable(bev, EV_READ);

		if (evbuffer_get_length(evbuf) == 8333) {
			test_ok++;
		}

		evbuffer_free(evbuf);
	}
}