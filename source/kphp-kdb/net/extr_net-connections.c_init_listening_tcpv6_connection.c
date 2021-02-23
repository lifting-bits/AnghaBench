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
typedef  int /*<<< orphan*/  conn_type_t ;

/* Variables and functions */
 int init_listening_connection_ext (int,int /*<<< orphan*/ *,void*,int,int) ; 

int init_listening_tcpv6_connection (int fd, conn_type_t *type, void *extra, int mode) {
  return init_listening_connection_ext (fd, type, extra, mode, -10);
}