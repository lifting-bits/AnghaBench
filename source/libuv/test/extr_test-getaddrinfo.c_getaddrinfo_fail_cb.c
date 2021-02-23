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
typedef  int /*<<< orphan*/  uv_getaddrinfo_t ;
struct addrinfo {int dummy; } ;

/* Variables and functions */
 int /*<<< orphan*/  ASSERT (int) ; 
 scalar_t__ fail_cb_called ; 
 int /*<<< orphan*/  uv_freeaddrinfo (struct addrinfo*) ; 

__attribute__((used)) static void getaddrinfo_fail_cb(uv_getaddrinfo_t* req,
                                int status,
                                struct addrinfo* res) {
  ASSERT(fail_cb_called == 0);
  ASSERT(status < 0);
  ASSERT(res == NULL);
  uv_freeaddrinfo(res);  /* Should not crash. */
  fail_cb_called++;
}