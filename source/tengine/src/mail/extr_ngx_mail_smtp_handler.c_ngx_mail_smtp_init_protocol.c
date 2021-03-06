#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_15__   TYPE_4__ ;
typedef  struct TYPE_14__   TYPE_3__ ;
typedef  struct TYPE_13__   TYPE_2__ ;
typedef  struct TYPE_12__   TYPE_1__ ;
typedef  struct TYPE_11__   TYPE_10__ ;

/* Type definitions */
struct TYPE_13__ {int /*<<< orphan*/  mail_state; int /*<<< orphan*/ * buffer; } ;
typedef  TYPE_2__ ngx_mail_session_t ;
struct TYPE_14__ {scalar_t__ timedout; TYPE_4__* data; } ;
typedef  TYPE_3__ ngx_event_t ;
struct TYPE_15__ {int timedout; TYPE_1__* read; TYPE_2__* data; TYPE_10__* log; } ;
typedef  TYPE_4__ ngx_connection_t ;
struct TYPE_12__ {int /*<<< orphan*/  (* handler ) (TYPE_3__*) ;} ;
struct TYPE_11__ {char* action; } ;

/* Variables and functions */
 int /*<<< orphan*/  NGX_ETIMEDOUT ; 
 int /*<<< orphan*/  NGX_LOG_INFO ; 
 scalar_t__ NGX_OK ; 
 int /*<<< orphan*/  ngx_log_error (int /*<<< orphan*/ ,TYPE_10__*,int /*<<< orphan*/ ,char*) ; 
 int /*<<< orphan*/  ngx_mail_close_connection (TYPE_4__*) ; 
 int /*<<< orphan*/  ngx_mail_smtp_auth_state (TYPE_3__*) ; 
 scalar_t__ ngx_mail_smtp_create_buffer (TYPE_2__*,TYPE_4__*) ; 
 int /*<<< orphan*/  ngx_smtp_start ; 

void
ngx_mail_smtp_init_protocol(ngx_event_t *rev)
{
    ngx_connection_t    *c;
    ngx_mail_session_t  *s;

    c = rev->data;

    c->log->action = "in auth state";

    if (rev->timedout) {
        ngx_log_error(NGX_LOG_INFO, c->log, NGX_ETIMEDOUT, "client timed out");
        c->timedout = 1;
        ngx_mail_close_connection(c);
        return;
    }

    s = c->data;

    if (s->buffer == NULL) {
        if (ngx_mail_smtp_create_buffer(s, c) != NGX_OK) {
            return;
        }
    }

    s->mail_state = ngx_smtp_start;
    c->read->handler = ngx_mail_smtp_auth_state;

    ngx_mail_smtp_auth_state(rev);
}