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
struct xdr_stream {int dummy; } ;
struct nfs_locku_res {int /*<<< orphan*/  stateid; int /*<<< orphan*/  seqid; } ;

/* Variables and functions */
 int EIO ; 
 int /*<<< orphan*/  OP_LOCKU ; 
 int decode_lock_stateid (struct xdr_stream*,int /*<<< orphan*/ *) ; 
 int decode_op_hdr (struct xdr_stream*,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  nfs_increment_lock_seqid (int,int /*<<< orphan*/ ) ; 

__attribute__((used)) static int decode_locku(struct xdr_stream *xdr, struct nfs_locku_res *res)
{
	int status;

	status = decode_op_hdr(xdr, OP_LOCKU);
	if (status != -EIO)
		nfs_increment_lock_seqid(status, res->seqid);
	if (status == 0)
		status = decode_lock_stateid(xdr, &res->stateid);
	return status;
}