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
struct rpc_query {long long qid; } ;
struct rpc_connection {int dummy; } ;

/* Variables and functions */
 int /*<<< orphan*/  MEMCACHE_DELETE ; 
 int /*<<< orphan*/  do_rpc_clean () ; 
 struct rpc_query* do_rpc_send_noflush (struct rpc_connection*,double) ; 
 int /*<<< orphan*/  do_rpc_store_header (int,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  do_rpc_store_int (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  do_rpc_store_string (char const*,int) ; 

long long do_memcache_send_delete (struct rpc_connection *c, const char *key, int key_len, double timeout) {
  do_rpc_clean ();
  do_rpc_store_header (1, 0);
  do_rpc_store_int (MEMCACHE_DELETE);
  do_rpc_store_string (key, key_len);
  struct rpc_query *q;
  if (!(q = do_rpc_send_noflush (c, timeout))) {
    return -1;
  }
  return q->qid;
}