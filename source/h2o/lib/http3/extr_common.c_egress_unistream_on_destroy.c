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
struct st_h2o_http3_egress_unistream_t {int /*<<< orphan*/  sendbuf; } ;
struct TYPE_3__ {struct st_h2o_http3_egress_unistream_t* data; } ;
typedef  TYPE_1__ quicly_stream_t ;

/* Variables and functions */
 int /*<<< orphan*/  free (struct st_h2o_http3_egress_unistream_t*) ; 
 int /*<<< orphan*/  h2o_buffer_dispose (int /*<<< orphan*/ *) ; 

__attribute__((used)) static void egress_unistream_on_destroy(quicly_stream_t *qs, int err)
{
    struct st_h2o_http3_egress_unistream_t *stream = qs->data;
    h2o_buffer_dispose(&stream->sendbuf);
    free(stream);
}