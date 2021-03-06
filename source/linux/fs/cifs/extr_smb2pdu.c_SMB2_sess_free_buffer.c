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
struct SMB2_sess_data {int /*<<< orphan*/  buf0_type; TYPE_1__* iov; } ;
struct TYPE_2__ {int /*<<< orphan*/  iov_base; } ;

/* Variables and functions */
 int /*<<< orphan*/  CIFS_NO_BUFFER ; 
 int /*<<< orphan*/  free_rsp_buf (int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 

__attribute__((used)) static void
SMB2_sess_free_buffer(struct SMB2_sess_data *sess_data)
{
	free_rsp_buf(sess_data->buf0_type, sess_data->iov[0].iov_base);
	sess_data->buf0_type = CIFS_NO_BUFFER;
}