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
struct smb2_sync_hdr {int /*<<< orphan*/  CreditCharge; } ;
struct TCP_Server_Info {int dummy; } ;

/* Variables and functions */
 unsigned int le16_to_cpu (int /*<<< orphan*/ ) ; 
 void revert_current_mid (struct TCP_Server_Info*,unsigned int) ; 

__attribute__((used)) static inline void
revert_current_mid_from_hdr(struct TCP_Server_Info *server,
			    const struct smb2_sync_hdr *shdr)
{
	unsigned int num = le16_to_cpu(shdr->CreditCharge);

	return revert_current_mid(server, num > 0 ? num : 1);
}