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
typedef  int /*<<< orphan*/  uint64_t ;
struct pt_insn_decoder {int /*<<< orphan*/  ip; int /*<<< orphan*/  query; } ;

/* Variables and functions */
 int /*<<< orphan*/  pt_insn_reset (struct pt_insn_decoder*) ; 
 int pt_insn_start (struct pt_insn_decoder*,int) ; 
 int pt_qry_sync_set (int /*<<< orphan*/ *,int /*<<< orphan*/ *,int /*<<< orphan*/ ) ; 
 int pte_invalid ; 

int pt_insn_sync_set(struct pt_insn_decoder *decoder, uint64_t offset)
{
	int status;

	if (!decoder)
		return -pte_invalid;

	pt_insn_reset(decoder);

	status = pt_qry_sync_set(&decoder->query, &decoder->ip, offset);

	return pt_insn_start(decoder, status);
}