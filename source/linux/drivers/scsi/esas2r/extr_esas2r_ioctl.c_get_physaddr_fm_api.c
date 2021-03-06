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
typedef  scalar_t__ u64 ;
typedef  scalar_t__ u32 ;
struct esas2r_sg_context {int cur_offset; scalar_t__ adapter; } ;
struct TYPE_2__ {scalar_t__ orig_len; scalar_t__ phys; } ;
struct esas2r_adapter {int save_offset; TYPE_1__ firmware; } ;

/* Variables and functions */

__attribute__((used)) static u32 get_physaddr_fm_api(struct esas2r_sg_context *sgc, u64 *addr)
{
	struct esas2r_adapter *a = (struct esas2r_adapter *)sgc->adapter;
	int offset = sgc->cur_offset - a->save_offset;

	(*addr) = a->firmware.phys + offset;
	return a->firmware.orig_len - offset;
}