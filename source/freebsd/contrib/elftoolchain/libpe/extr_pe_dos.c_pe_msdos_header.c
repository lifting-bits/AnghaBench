#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_3__   TYPE_1__ ;

/* Type definitions */
struct TYPE_3__ {int /*<<< orphan*/ * pe_dh; } ;
typedef  int /*<<< orphan*/  PE_DosHdr ;
typedef  TYPE_1__ PE ;

/* Variables and functions */
 int /*<<< orphan*/  EINVAL ; 
 int /*<<< orphan*/  ENOENT ; 
 int /*<<< orphan*/  errno ; 

PE_DosHdr *
pe_msdos_header(PE *pe)
{

	if (pe == NULL) {
		errno = EINVAL;
		return (NULL);
	}

	if (pe->pe_dh == NULL) {
		errno = ENOENT;
		return (NULL);
	}

	return (pe->pe_dh);
}