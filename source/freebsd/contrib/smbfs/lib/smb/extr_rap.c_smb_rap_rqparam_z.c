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
struct smb_rap {int r_npbuf; int r_plen; } ;

/* Variables and functions */
 int /*<<< orphan*/  bcopy (char const*,int,int) ; 
 int strlen (char const*) ; 

__attribute__((used)) static int
smb_rap_rqparam_z(struct smb_rap *rap, const char *value)
{
	int len = strlen(value) + 1;

	bcopy(value, rap->r_npbuf, len);
	rap->r_npbuf += len;
	rap->r_plen += len;
	return 0;
}