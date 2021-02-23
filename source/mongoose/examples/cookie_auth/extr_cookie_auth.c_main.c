#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_2__   TYPE_1__ ;

/* Type definitions */
struct mg_mgr {int dummy; } ;
struct mg_connection {int dummy; } ;
struct TYPE_2__ {char* document_root; } ;

/* Variables and functions */
 scalar_t__ SESSION_CHECK_INTERVAL ; 
 int /*<<< orphan*/  ev_handler ; 
 int /*<<< orphan*/  login_handler ; 
 int /*<<< orphan*/  logout_handler ; 
 struct mg_connection* mg_bind (struct mg_mgr*,char*,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  mg_mgr_free (struct mg_mgr*) ; 
 int /*<<< orphan*/  mg_mgr_init (struct mg_mgr*,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  mg_mgr_poll (struct mg_mgr*,int) ; 
 int /*<<< orphan*/  mg_register_http_endpoint (struct mg_connection*,char*,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  mg_set_protocol_http_websocket (struct mg_connection*) ; 
 int /*<<< orphan*/  mg_set_timer (struct mg_connection*,scalar_t__) ; 
 scalar_t__ mg_time () ; 
 int /*<<< orphan*/  printf (char*,char*) ; 
 char* s_http_port ; 
 TYPE_1__ s_http_server_opts ; 
 int /*<<< orphan*/  srand (scalar_t__) ; 

int main(void) {
  struct mg_mgr mgr;
  struct mg_connection *nc;
  srand(mg_time());

  mg_mgr_init(&mgr, NULL);
  nc = mg_bind(&mgr, s_http_port, ev_handler);

  mg_set_protocol_http_websocket(nc);
  s_http_server_opts.document_root = ".";
  mg_register_http_endpoint(nc, "/login.html", login_handler);
  mg_register_http_endpoint(nc, "/logout", logout_handler);
  mg_set_timer(nc, mg_time() + SESSION_CHECK_INTERVAL);

  printf("Starting web server on port %s\n", s_http_port);
  for (;;) {
    mg_mgr_poll(&mgr, 1000);
  }
  mg_mgr_free(&mgr);

  return 0;
}