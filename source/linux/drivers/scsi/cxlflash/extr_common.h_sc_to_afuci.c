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
struct scsi_cmnd {int dummy; } ;
struct afu_cmd {int /*<<< orphan*/  queue; } ;

/* Variables and functions */
 int /*<<< orphan*/  INIT_LIST_HEAD (int /*<<< orphan*/ *) ; 
 struct afu_cmd* sc_to_afuc (struct scsi_cmnd*) ; 

__attribute__((used)) static inline struct afu_cmd *sc_to_afuci(struct scsi_cmnd *sc)
{
	struct afu_cmd *afuc = sc_to_afuc(sc);

	INIT_LIST_HEAD(&afuc->queue);
	return afuc;
}