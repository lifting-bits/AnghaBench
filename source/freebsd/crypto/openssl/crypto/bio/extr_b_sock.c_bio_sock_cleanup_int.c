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

/* Variables and functions */
 int /*<<< orphan*/  WSACleanup () ; 
 scalar_t__ wsa_init_done ; 

void bio_sock_cleanup_int(void)
{
# ifdef OPENSSL_SYS_WINDOWS
    if (wsa_init_done) {
        wsa_init_done = 0;
        WSACleanup();
    }
# endif
}