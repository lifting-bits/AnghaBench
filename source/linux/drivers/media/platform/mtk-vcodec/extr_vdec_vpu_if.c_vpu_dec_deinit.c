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
struct vdec_vpu_inst {int dummy; } ;

/* Variables and functions */
 int /*<<< orphan*/  AP_IPIMSG_DEC_DEINIT ; 
 int vcodec_send_ap_ipi (struct vdec_vpu_inst*,int /*<<< orphan*/ ) ; 

int vpu_dec_deinit(struct vdec_vpu_inst *vpu)
{
	return vcodec_send_ap_ipi(vpu, AP_IPIMSG_DEC_DEINIT);
}