#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_6__   TYPE_2__ ;
typedef  struct TYPE_5__   TYPE_1__ ;

/* Type definitions */
struct TYPE_5__ {scalar_t__ ssl; } ;
struct TYPE_6__ {TYPE_1__ dnstls_data; struct TYPE_6__* encrypted; } ;
typedef  TYPE_2__ DnsStream ;

/* Variables and functions */
 int /*<<< orphan*/  SSL_free (scalar_t__) ; 
 int /*<<< orphan*/  assert (TYPE_2__*) ; 

void dnstls_stream_free(DnsStream *stream) {
        assert(stream);
        assert(stream->encrypted);

        if (stream->dnstls_data.ssl)
                SSL_free(stream->dnstls_data.ssl);
}