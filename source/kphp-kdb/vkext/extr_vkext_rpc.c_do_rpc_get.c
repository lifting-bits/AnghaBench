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
struct rpc_query {double timeout; char* answer; int answer_len; scalar_t__ start_time; } ;

/* Variables and functions */
 int /*<<< orphan*/  ADD_CNT (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  END_TIMER (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  START_TIMER (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  assert (struct rpc_query*) ; 
 int /*<<< orphan*/  rpc_get ; 
 int /*<<< orphan*/  rpc_get_and_parse ; 
 int rpc_get_answer (struct rpc_query*,double) ; 
 int /*<<< orphan*/  rpc_query_delete_nobuf (struct rpc_query*) ; 
 struct rpc_query* rpc_query_get (long long) ; 

int do_rpc_get (long long qid, double timeout, char **value) { /* {{{ */
  ADD_CNT (rpc_get);
  START_TIMER (rpc_get);
  struct rpc_query *q = rpc_query_get (qid);
  if (!q) {
    END_TIMER (rpc_get);
    return -1;
  }
  if (timeout >= 0) {
    timeout += q->start_time;
  } else {
    timeout = q->timeout;
  }
  int r = rpc_get_answer (q, timeout);
  if (r < 0) {
    END_TIMER (rpc_get);
    return -1;
  } else {
    //struct rpc_query *q = rpc_query_get (qid);
    assert (q);
    *value = q->answer;
    int r = q->answer_len;
    rpc_query_delete_nobuf (q);    
    END_TIMER (rpc_get_and_parse);
    return r;
  }
}