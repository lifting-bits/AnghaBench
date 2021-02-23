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
struct cumanascsi2_info {int /*<<< orphan*/  info; scalar_t__ terms; } ;
struct Scsi_Host {scalar_t__ hostdata; } ;
typedef  long off_t ;

/* Variables and functions */
 char* VERSION ; 
 int cumanascsi_2_set_proc_info (struct Scsi_Host*,char*,int) ; 
 int /*<<< orphan*/  fas216_print_devices (int /*<<< orphan*/ *,char*) ; 
 int /*<<< orphan*/  fas216_print_host (int /*<<< orphan*/ *,char*) ; 
 int /*<<< orphan*/  fas216_print_stats (int /*<<< orphan*/ *,char*) ; 
 int /*<<< orphan*/  sprintf (char*,char*,char*) ; 

int cumanascsi_2_proc_info (struct Scsi_Host *host, char *buffer, char **start, off_t offset,
			    int length, int inout)
{
	struct cumanascsi2_info *info;
	char *p = buffer;
	int pos;

	if (inout == 1)
		return cumanascsi_2_set_proc_info(host, buffer, length);

	info = (struct cumanascsi2_info *)host->hostdata;

	p += sprintf(p, "Cumana SCSI II driver v%s\n", VERSION);
	p += fas216_print_host(&info->info, p);
	p += sprintf(p, "Term    : o%s\n",
			info->terms ? "n" : "ff");

	p += fas216_print_stats(&info->info, p);
	p += fas216_print_devices(&info->info, p);

	*start = buffer + offset;
	pos = p - buffer - offset;
	if (pos > length)
		pos = length;

	return pos;
}