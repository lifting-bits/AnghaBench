#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_4__   TYPE_2__ ;
typedef  struct TYPE_3__   TYPE_1__ ;

/* Type definitions */
struct mg_serve_http_opts {char* document_root; } ;
struct mg_http_multipart_part {int /*<<< orphan*/  file_name; } ;
struct mg_connection {int /*<<< orphan*/  flags; int /*<<< orphan*/  sa; } ;
struct TYPE_4__ {int /*<<< orphan*/  p; scalar_t__ len; } ;
struct TYPE_3__ {int /*<<< orphan*/  p; scalar_t__ len; } ;
struct http_message {TYPE_2__ uri; TYPE_1__ method; } ;
typedef  int /*<<< orphan*/  opts ;
typedef  int /*<<< orphan*/  cs_stat_t ;
typedef  int /*<<< orphan*/  addr ;

/* Variables and functions */
 int /*<<< orphan*/  LL_DEBUG ; 
 int /*<<< orphan*/  LL_INFO ; 
 int /*<<< orphan*/  LOG (int /*<<< orphan*/ ,char*) ; 
#define  MG_EV_ACCEPT 133 
#define  MG_EV_CLOSE 132 
#define  MG_EV_HTTP_PART_BEGIN 131 
#define  MG_EV_HTTP_PART_DATA 130 
#define  MG_EV_HTTP_PART_END 129 
#define  MG_EV_HTTP_REQUEST 128 
 int /*<<< orphan*/  MG_F_SEND_AND_CLOSE ; 
 int MG_SOCK_STRINGIFY_IP ; 
 int MG_SOCK_STRINGIFY_PORT ; 
 int /*<<< orphan*/  memset (struct mg_serve_http_opts*,int /*<<< orphan*/ ,int) ; 
 int /*<<< orphan*/  mg_file_upload_handler (struct mg_connection*,int,void*,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  mg_send (struct mg_connection*,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  mg_serve_http (struct mg_connection*,struct http_message*,struct mg_serve_http_opts) ; 
 int /*<<< orphan*/  mg_sock_addr_to_str (int /*<<< orphan*/ *,char*,int,int) ; 
 int /*<<< orphan*/  mg_stat (char*,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  mg_vcmp (TYPE_2__*,char*) ; 
 int /*<<< orphan*/  strlen (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  upload_fname ; 
 int /*<<< orphan*/  upload_form ; 

void mg_ev_handler(struct mg_connection *nc, int ev, void *ev_data) {
  LOG(LL_DEBUG, ("%p ev %d", nc, ev));

  switch (ev) {
    case MG_EV_ACCEPT: {
      char addr[32];
      mg_sock_addr_to_str(&nc->sa, addr, sizeof(addr),
                          MG_SOCK_STRINGIFY_IP | MG_SOCK_STRINGIFY_PORT);
      LOG(LL_INFO, ("Connection %p from %s", nc, addr));
      break;
    }
    case MG_EV_HTTP_REQUEST: {
      char addr[32];
      struct http_message *hm = (struct http_message *) ev_data;
      cs_stat_t st;
      mg_sock_addr_to_str(&nc->sa, addr, sizeof(addr),
                          MG_SOCK_STRINGIFY_IP | MG_SOCK_STRINGIFY_PORT);
      LOG(LL_INFO,
          ("HTTP request from %s: %.*s %.*s", addr, (int) hm->method.len,
           hm->method.p, (int) hm->uri.len, hm->uri.p));
      if (mg_vcmp(&hm->uri, "/upload") == 0 ||
          (mg_vcmp(&hm->uri, "/") == 0 && mg_stat("SL:index.html", &st) != 0)) {
        mg_send(nc, upload_form, strlen(upload_form));
        nc->flags |= MG_F_SEND_AND_CLOSE;
        break;
      }
      struct mg_serve_http_opts opts;
      memset(&opts, 0, sizeof(opts));
      opts.document_root = "SL:";
      mg_serve_http(nc, hm, opts);
      break;
    }
    case MG_EV_CLOSE: {
      LOG(LL_INFO, ("Connection %p closed", nc));
      break;
    }
    case MG_EV_HTTP_PART_BEGIN:
    case MG_EV_HTTP_PART_DATA:
    case MG_EV_HTTP_PART_END: {
      struct mg_http_multipart_part *mp =
          (struct mg_http_multipart_part *) ev_data;
      if (ev == MG_EV_HTTP_PART_BEGIN) {
        LOG(LL_INFO, ("Begin file upload: %s", mp->file_name));
      } else if (ev == MG_EV_HTTP_PART_END) {
        LOG(LL_INFO, ("End file upload: %s", mp->file_name));
      }
      mg_file_upload_handler(nc, ev, ev_data, upload_fname);
    }
  }
}