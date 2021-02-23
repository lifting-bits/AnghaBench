#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_4__   TYPE_2__ ;
typedef  struct TYPE_3__   TYPE_1__ ;

/* Type definitions */
struct nfs_pgio_header {TYPE_2__* completion_ops; int /*<<< orphan*/  refcnt; int /*<<< orphan*/  rpc_list; int /*<<< orphan*/  lseg; } ;
struct nfs_write_header {struct nfs_pgio_header header; } ;
struct nfs_pageio_descriptor {int /*<<< orphan*/  pg_ioflags; int /*<<< orphan*/ * pg_lseg; int /*<<< orphan*/  pg_list; TYPE_1__* pg_completion_ops; } ;
struct TYPE_4__ {int /*<<< orphan*/  (* completion ) (struct nfs_pgio_header*) ;} ;
struct TYPE_3__ {int /*<<< orphan*/  (* error_cleanup ) (int /*<<< orphan*/ *) ;} ;

/* Variables and functions */
 int ENOMEM ; 
 scalar_t__ atomic_dec_and_test (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  atomic_inc (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  get_lseg (int /*<<< orphan*/ *) ; 
 int nfs_generic_flush (struct nfs_pageio_descriptor*,struct nfs_pgio_header*) ; 
 int /*<<< orphan*/  nfs_pgheader_init (struct nfs_pageio_descriptor*,struct nfs_pgio_header*,int /*<<< orphan*/ ) ; 
 struct nfs_write_header* nfs_writehdr_alloc () ; 
 int /*<<< orphan*/  pnfs_do_multiple_writes (struct nfs_pageio_descriptor*,int /*<<< orphan*/ *,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  pnfs_writehdr_free ; 
 int /*<<< orphan*/  put_lseg (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  stub1 (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  stub2 (struct nfs_pgio_header*) ; 

int
pnfs_generic_pg_writepages(struct nfs_pageio_descriptor *desc)
{
	struct nfs_write_header *whdr;
	struct nfs_pgio_header *hdr;
	int ret;

	whdr = nfs_writehdr_alloc();
	if (!whdr) {
		desc->pg_completion_ops->error_cleanup(&desc->pg_list);
		put_lseg(desc->pg_lseg);
		desc->pg_lseg = NULL;
		return -ENOMEM;
	}
	hdr = &whdr->header;
	nfs_pgheader_init(desc, hdr, pnfs_writehdr_free);
	hdr->lseg = get_lseg(desc->pg_lseg);
	atomic_inc(&hdr->refcnt);
	ret = nfs_generic_flush(desc, hdr);
	if (ret != 0) {
		put_lseg(desc->pg_lseg);
		desc->pg_lseg = NULL;
	} else
		pnfs_do_multiple_writes(desc, &hdr->rpc_list, desc->pg_ioflags);
	if (atomic_dec_and_test(&hdr->refcnt))
		hdr->completion_ops->completion(hdr);
	return ret;
}