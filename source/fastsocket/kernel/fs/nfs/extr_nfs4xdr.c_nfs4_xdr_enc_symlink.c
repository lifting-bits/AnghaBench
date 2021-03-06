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
struct rpc_rqst {int dummy; } ;
struct nfs4_create_arg {int dummy; } ;
typedef  int /*<<< orphan*/  __be32 ;

/* Variables and functions */
 int nfs4_xdr_enc_create (struct rpc_rqst*,int /*<<< orphan*/ *,struct nfs4_create_arg const*) ; 

__attribute__((used)) static int nfs4_xdr_enc_symlink(struct rpc_rqst *req, __be32 *p, const struct nfs4_create_arg *args)
{
	return nfs4_xdr_enc_create(req, p, args);
}