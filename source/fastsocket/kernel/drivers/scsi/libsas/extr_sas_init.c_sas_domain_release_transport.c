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
struct scsi_transport_template {int dummy; } ;

/* Variables and functions */
 int /*<<< orphan*/  sas_release_transport (struct scsi_transport_template*) ; 

void sas_domain_release_transport(struct scsi_transport_template *stt)
{
	sas_release_transport(stt);
}