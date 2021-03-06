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
struct ncp_volume_info {int /*<<< orphan*/  volume_name; void* sectors_per_block; void* available_dir_entries; void* total_dir_entries; void* not_yet_purgeable_blocks; void* purgeable_blocks; void* free_blocks; void* total_blocks; } ;
struct ncp_server {int dummy; } ;

/* Variables and functions */
 int /*<<< orphan*/  DPRINTK (char*,int) ; 
 int EIO ; 
 int NCP_VOLNAME_LEN ; 
 int /*<<< orphan*/  memcpy (int /*<<< orphan*/ *,int /*<<< orphan*/ ,int) ; 
 int /*<<< orphan*/  memset (int /*<<< orphan*/ *,int /*<<< orphan*/ ,int) ; 
 int /*<<< orphan*/  ncp_add_byte (struct ncp_server*,int) ; 
 int /*<<< orphan*/  ncp_init_request_s (struct ncp_server*,int) ; 
 void* ncp_reply_byte (struct ncp_server*,int) ; 
 int /*<<< orphan*/  ncp_reply_data (struct ncp_server*,int) ; 
 void* ncp_reply_dword_lh (struct ncp_server*,int) ; 
 int ncp_request (struct ncp_server*,int) ; 
 int /*<<< orphan*/  ncp_unlock_server (struct ncp_server*) ; 

int ncp_get_volume_info_with_number(struct ncp_server* server,
			     int n, struct ncp_volume_info* target) {
	int result;
	int len;

	ncp_init_request_s(server, 44);
	ncp_add_byte(server, n);

	if ((result = ncp_request(server, 22)) != 0) {
		goto out;
	}
	target->total_blocks = ncp_reply_dword_lh(server, 0);
	target->free_blocks = ncp_reply_dword_lh(server, 4);
	target->purgeable_blocks = ncp_reply_dword_lh(server, 8);
	target->not_yet_purgeable_blocks = ncp_reply_dword_lh(server, 12);
	target->total_dir_entries = ncp_reply_dword_lh(server, 16);
	target->available_dir_entries = ncp_reply_dword_lh(server, 20);
	target->sectors_per_block = ncp_reply_byte(server, 28);

	memset(&(target->volume_name), 0, sizeof(target->volume_name));

	result = -EIO;
	len = ncp_reply_byte(server, 29);
	if (len > NCP_VOLNAME_LEN) {
		DPRINTK("ncpfs: volume name too long: %d\n", len);
		goto out;
	}
	memcpy(&(target->volume_name), ncp_reply_data(server, 30), len);
	result = 0;
out:
	ncp_unlock_server(server);
	return result;
}