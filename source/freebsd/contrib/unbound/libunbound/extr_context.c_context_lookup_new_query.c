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
typedef  int /*<<< orphan*/  uint8_t ;
typedef  int uint32_t ;
struct ub_ctx {int /*<<< orphan*/  queries; } ;
struct ctx_query {int async; } ;

/* Variables and functions */
 scalar_t__ UB_LIBCMD_NEWQUERY ; 
 int /*<<< orphan*/  log_assert (int) ; 
 scalar_t__ rbtree_search (int /*<<< orphan*/ *,int*) ; 
 scalar_t__ sldns_read_uint32 (int /*<<< orphan*/ *) ; 

struct ctx_query* 
context_lookup_new_query(struct ub_ctx* ctx, uint8_t* p, uint32_t len)
{
	struct ctx_query* q;
	int querynum;
	if(len < 4*sizeof(uint32_t)+1) {
		return NULL;
	}
	log_assert( sldns_read_uint32(p) == UB_LIBCMD_NEWQUERY);
	querynum = (int)sldns_read_uint32(p+sizeof(uint32_t));
	q = (struct ctx_query*)rbtree_search(&ctx->queries, &querynum);
	if(!q) {
		return NULL;
	}
	log_assert(q->async);
	return q;
}