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
typedef  int /*<<< orphan*/  ev_uint8_t ;
typedef  int /*<<< orphan*/  ev_uint32_t ;

/* Variables and functions */
 int encode_int_internal (int /*<<< orphan*/ *,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  evbuffer_add (struct evbuffer*,int /*<<< orphan*/ *,int) ; 
 int /*<<< orphan*/  evtag_encode_int (struct evbuffer*,int) ; 
 int /*<<< orphan*/  evtag_encode_tag (struct evbuffer*,int /*<<< orphan*/ ) ; 

void
evtag_marshal_int(struct evbuffer *evbuf, ev_uint32_t tag, ev_uint32_t integer)
{
	ev_uint8_t data[5];
	int len = encode_int_internal(data, integer);

	evtag_encode_tag(evbuf, tag);
	evtag_encode_int(evbuf, len);
	evbuffer_add(evbuf, data, len);
}