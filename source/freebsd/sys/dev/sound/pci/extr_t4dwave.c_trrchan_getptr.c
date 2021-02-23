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
typedef  scalar_t__ u_int32_t ;
struct tr_rchinfo {int /*<<< orphan*/  buffer; struct tr_info* parent; } ;
struct tr_info {int dummy; } ;
typedef  int /*<<< orphan*/  kobj_t ;

/* Variables and functions */
 int /*<<< orphan*/  TR_REG_DMAR0 ; 
 scalar_t__ sndbuf_getbufaddr (int /*<<< orphan*/ ) ; 
 scalar_t__ tr_rd (struct tr_info*,int /*<<< orphan*/ ,int) ; 

__attribute__((used)) static u_int32_t
trrchan_getptr(kobj_t obj, void *data)
{
 	struct tr_rchinfo *ch = data;
	struct tr_info *tr = ch->parent;

	/* return current byte offset of channel */
	return tr_rd(tr, TR_REG_DMAR0, 4) - sndbuf_getbufaddr(ch->buffer);
}