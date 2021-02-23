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
struct smb_sb_info {int dummy; } ;
struct smb_request {char* rq_buffer; char* rq_data; int rq_lparm; char* rq_parm; int /*<<< orphan*/  rq_err; int /*<<< orphan*/  rq_rcls; scalar_t__ rq_flags; int /*<<< orphan*/  rq_trans2_command; void* rq_ldata; } ;
struct dentry {int dummy; } ;

/* Variables and functions */
 int /*<<< orphan*/  DEBUG1 (char*,char*,int,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  DSET (char*,int,int /*<<< orphan*/ ) ; 
 int ENOMEM ; 
 int /*<<< orphan*/  PAGE_SIZE ; 
 scalar_t__ SMB_MAXPATHLEN ; 
 int /*<<< orphan*/  SMB_SET_FILE_UNIX_HLINK ; 
 int /*<<< orphan*/  TRANSACT2_SETPATHINFO ; 
 int /*<<< orphan*/  WSET (char*,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int smb_add_request (struct smb_request*) ; 
 struct smb_request* smb_alloc_request (struct smb_sb_info*,int /*<<< orphan*/ ) ; 
 void* smb_encode_path (struct smb_sb_info*,char*,scalar_t__,struct dentry*,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  smb_rput (struct smb_request*) ; 

int
smb_proc_link(struct smb_sb_info *server, struct dentry *dentry,
	      struct dentry *new_dentry)
{
	char *p, *param;
	int result;
	struct smb_request *req;

	result = -ENOMEM;
	if (! (req = smb_alloc_request(server, PAGE_SIZE)))
		goto out;
	param = req->rq_buffer;

	WSET(param, 0, SMB_SET_FILE_UNIX_HLINK);
	DSET(param, 2, 0);
	result = smb_encode_path(server, param + 6, SMB_MAXPATHLEN+1,
				 new_dentry, NULL);
	if (result < 0)
		goto out_free;
	p = param + 6 + result;

	/* Grr, pointless separation of parameters and data ... */
	req->rq_data = p;
	req->rq_ldata = smb_encode_path(server, p, SMB_MAXPATHLEN+1,
					dentry, NULL);

	req->rq_trans2_command = TRANSACT2_SETPATHINFO;
	req->rq_lparm = p - param;
	req->rq_parm  = param;
	req->rq_flags = 0;
	result = smb_add_request(req);
	if (result < 0)
		goto out_free;

	DEBUG1("for %s: result=%d, rcls=%d, err=%d\n",
	       &param[6], result, req->rq_rcls, req->rq_err);
	result = 0;

out_free:
	smb_rput(req);
out:
	return result;
}