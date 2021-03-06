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
struct TYPE_5__ {int /*<<< orphan*/  (* write ) (TYPE_2__*,char const*) ;} ;
struct TYPE_6__ {TYPE_1__ _cb; int /*<<< orphan*/ * ssl; } ;
typedef  TYPE_2__ h2o_socket_t ;
typedef  int /*<<< orphan*/  (* h2o_socket_cb ) (TYPE_2__*,char const*) ;

/* Variables and functions */
 int /*<<< orphan*/  clear_output_buffer (int /*<<< orphan*/ *) ; 

void on_write_complete(h2o_socket_t *sock, const char *err)
{
    h2o_socket_cb cb;

    if (sock->ssl != NULL)
        clear_output_buffer(sock->ssl);

    cb = sock->_cb.write;
    sock->_cb.write = NULL;
    cb(sock, err);
}