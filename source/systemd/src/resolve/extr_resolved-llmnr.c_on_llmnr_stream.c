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
typedef  int /*<<< orphan*/  uint32_t ;
typedef  int /*<<< orphan*/  sd_event_source ;
struct TYPE_3__ {int /*<<< orphan*/  on_packet; } ;
typedef  int /*<<< orphan*/  Manager ;
typedef  TYPE_1__ DnsStream ;

/* Variables and functions */
 int /*<<< orphan*/  DNS_PROTOCOL_LLMNR ; 
 int /*<<< orphan*/  DNS_STREAM_LLMNR_RECV ; 
 scalar_t__ ERRNO_IS_ACCEPT_AGAIN (int) ; 
 int SOCK_CLOEXEC ; 
 int SOCK_NONBLOCK ; 
 int accept4 (int,int /*<<< orphan*/ *,int /*<<< orphan*/ *,int) ; 
 int dns_stream_new (int /*<<< orphan*/ *,TYPE_1__**,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int,int /*<<< orphan*/ *) ; 
 int errno ; 
 int /*<<< orphan*/  on_llmnr_stream_packet ; 
 int /*<<< orphan*/  safe_close (int) ; 

__attribute__((used)) static int on_llmnr_stream(sd_event_source *s, int fd, uint32_t revents, void *userdata) {
        DnsStream *stream;
        Manager *m = userdata;
        int cfd, r;

        cfd = accept4(fd, NULL, NULL, SOCK_NONBLOCK|SOCK_CLOEXEC);
        if (cfd < 0) {
                if (ERRNO_IS_ACCEPT_AGAIN(errno))
                        return 0;

                return -errno;
        }

        r = dns_stream_new(m, &stream, DNS_STREAM_LLMNR_RECV, DNS_PROTOCOL_LLMNR, cfd, NULL);
        if (r < 0) {
                safe_close(cfd);
                return r;
        }

        stream->on_packet = on_llmnr_stream_packet;
        /* We don't configure a "complete" handler here, we rely on the default handler than simply drops the
         * reference to the stream, thus freeing it */
        return 0;
}