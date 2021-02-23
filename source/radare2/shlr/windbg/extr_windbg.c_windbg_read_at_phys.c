#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_9__   TYPE_3__ ;
typedef  struct TYPE_8__   TYPE_2__ ;
typedef  struct TYPE_7__   TYPE_1__ ;

/* Type definitions */
typedef  int /*<<< orphan*/  ut64 ;
typedef  int /*<<< orphan*/  uint8_t ;
struct TYPE_7__ {int read; int /*<<< orphan*/  length; int /*<<< orphan*/  addr; } ;
struct TYPE_8__ {TYPE_1__ r_mem; int /*<<< orphan*/  data; scalar_t__ ret; int /*<<< orphan*/  cpu; int /*<<< orphan*/  req; int /*<<< orphan*/  member_0; } ;
typedef  TYPE_2__ kd_req_t ;
typedef  int /*<<< orphan*/  kd_packet_t ;
struct TYPE_9__ {int seq_id; int /*<<< orphan*/  io_ptr; int /*<<< orphan*/  cpu; int /*<<< orphan*/  syncd; } ;
typedef  TYPE_3__ WindCtx ;

/* Variables and functions */
 int /*<<< orphan*/  DbgKdReadPhysicalMemoryApi ; 
 int KD_E_OK ; 
 int /*<<< orphan*/  KD_MAX_PAYLOAD ; 
 int /*<<< orphan*/  KD_PACKET_TYPE_ACKNOWLEDGE ; 
 int /*<<< orphan*/  KD_PACKET_TYPE_STATE_MANIPULATE ; 
 TYPE_2__* PKT_REQ (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  R_MIN (int const,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  free (int /*<<< orphan*/ *) ; 
 int kd_send_data_packet (int /*<<< orphan*/ ,int /*<<< orphan*/ ,int,int /*<<< orphan*/ *,int,int /*<<< orphan*/ *,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  memcpy (int /*<<< orphan*/ *,int /*<<< orphan*/ ,int) ; 
 int windbg_wait_packet (TYPE_3__*,int /*<<< orphan*/ ,int /*<<< orphan*/ **) ; 

int windbg_read_at_phys(WindCtx *ctx, uint8_t *buf, const ut64 offset, const int count) {
	kd_req_t req = {
		0
	}, *rr;
	kd_packet_t *pkt;
	int ret;

	if (!ctx || !ctx->io_ptr || !ctx->syncd) {
		return 0;
	}
	req.req = DbgKdReadPhysicalMemoryApi;
	req.cpu = ctx->cpu;
	req.r_mem.addr = offset;
	req.r_mem.length = R_MIN (count, KD_MAX_PAYLOAD);
	req.r_mem.read = 0;	// Default caching option

	ret = kd_send_data_packet (ctx->io_ptr, KD_PACKET_TYPE_STATE_MANIPULATE, (ctx->seq_id ^= 1),
		(uint8_t *) &req, sizeof(kd_req_t), NULL, 0);
	if (ret != KD_E_OK) {
		return 0;
	}

	ret = windbg_wait_packet (ctx, KD_PACKET_TYPE_ACKNOWLEDGE, NULL);
	if (ret != KD_E_OK) {
		return 0;
	}

	ret = windbg_wait_packet (ctx, KD_PACKET_TYPE_STATE_MANIPULATE, &pkt);
	if (ret != KD_E_OK) {
		return 0;
	}

	rr = PKT_REQ (pkt);

	if (rr->ret) {
		free (pkt);
		return 0;
	}

	memcpy (buf, rr->data, rr->r_mem.read);
	ret = rr->r_mem.read;
	free (pkt);
	return ret;
}