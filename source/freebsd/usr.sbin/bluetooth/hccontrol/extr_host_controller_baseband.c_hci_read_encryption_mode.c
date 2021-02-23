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
typedef  int /*<<< orphan*/  rp ;
struct TYPE_2__ {int status; int encryption_mode; } ;
typedef  TYPE_1__ ng_hci_read_encryption_mode_rp ;

/* Variables and functions */
 scalar_t__ ERROR ; 
 int FAILED ; 
 int /*<<< orphan*/  NG_HCI_OCF_READ_ENCRYPTION_MODE ; 
 int /*<<< orphan*/  NG_HCI_OGF_HC_BASEBAND ; 
 int /*<<< orphan*/  NG_HCI_OPCODE (int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int OK ; 
 int /*<<< orphan*/  fprintf (int /*<<< orphan*/ ,char*,char*,int) ; 
 char* hci_encrypt2str (int,int /*<<< orphan*/ ) ; 
 scalar_t__ hci_simple_request (int,int /*<<< orphan*/ ,char*,int*) ; 
 char* hci_status2str (int) ; 
 int /*<<< orphan*/  stdout ; 

__attribute__((used)) static int
hci_read_encryption_mode(int s, int argc, char **argv)
{
	ng_hci_read_encryption_mode_rp	rp;
	int				n;

	n = sizeof(rp);
	if (hci_simple_request(s, NG_HCI_OPCODE(NG_HCI_OGF_HC_BASEBAND,
			NG_HCI_OCF_READ_ENCRYPTION_MODE),
			(char *) &rp, &n) == ERROR)
		return (ERROR);

	if (rp.status != 0x00) {
		fprintf(stdout, "Status: %s [%#02x]\n", 
			hci_status2str(rp.status), rp.status);
		return (FAILED);
	}

	fprintf(stdout, "Encryption mode: %s [%#02x]\n", 
		hci_encrypt2str(rp.encryption_mode, 0), rp.encryption_mode);

	return (OK);
}