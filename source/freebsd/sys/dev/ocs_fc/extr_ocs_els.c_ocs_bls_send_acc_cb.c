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
typedef  int /*<<< orphan*/  uint32_t ;
typedef  int /*<<< orphan*/  ocs_remote_node_t ;
typedef  int /*<<< orphan*/  ocs_io_t ;
typedef  int /*<<< orphan*/  ocs_hw_io_t ;
typedef  int /*<<< orphan*/  int32_t ;

/* Variables and functions */
 int /*<<< orphan*/  ocs_assert (int /*<<< orphan*/ *,int) ; 
 int /*<<< orphan*/  ocs_scsi_io_free (int /*<<< orphan*/ *) ; 

__attribute__((used)) static int32_t
ocs_bls_send_acc_cb(ocs_hw_io_t *hio, ocs_remote_node_t *rnode, uint32_t length, int32_t status, uint32_t ext_status, void *app)
{
	ocs_io_t *io = app;

	ocs_assert(io, -1);

	ocs_scsi_io_free(io);
	return 0;
}