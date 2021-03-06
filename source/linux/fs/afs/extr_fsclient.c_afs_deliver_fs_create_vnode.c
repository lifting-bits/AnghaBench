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
struct afs_call {int /*<<< orphan*/  out_volsync; int /*<<< orphan*/  out_scb; int /*<<< orphan*/  out_dir_scb; int /*<<< orphan*/  out_fid; int /*<<< orphan*/ * buffer; } ;
typedef  int /*<<< orphan*/  __be32 ;

/* Variables and functions */
 int /*<<< orphan*/  _leave (char*) ; 
 int afs_transfer_reply (struct afs_call*) ; 
 int /*<<< orphan*/  xdr_decode_AFSCallBack (int /*<<< orphan*/  const**,struct afs_call*,int /*<<< orphan*/ ) ; 
 int xdr_decode_AFSFetchStatus (int /*<<< orphan*/  const**,struct afs_call*,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  xdr_decode_AFSFid (int /*<<< orphan*/  const**,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  xdr_decode_AFSVolSync (int /*<<< orphan*/  const**,int /*<<< orphan*/ ) ; 

__attribute__((used)) static int afs_deliver_fs_create_vnode(struct afs_call *call)
{
	const __be32 *bp;
	int ret;

	ret = afs_transfer_reply(call);
	if (ret < 0)
		return ret;

	/* unmarshall the reply once we've received all of it */
	bp = call->buffer;
	xdr_decode_AFSFid(&bp, call->out_fid);
	ret = xdr_decode_AFSFetchStatus(&bp, call, call->out_scb);
	if (ret < 0)
		return ret;
	ret = xdr_decode_AFSFetchStatus(&bp, call, call->out_dir_scb);
	if (ret < 0)
		return ret;
	xdr_decode_AFSCallBack(&bp, call, call->out_scb);
	xdr_decode_AFSVolSync(&bp, call->out_volsync);

	_leave(" = 0 [done]");
	return 0;
}