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
struct lm_lockstruct {unsigned int ls_recover_jid_done; unsigned int ls_recover_jid_status; } ;
struct gfs2_sbd {int /*<<< orphan*/  sd_kobj; struct lm_lockstruct sd_lockstruct; } ;

/* Variables and functions */
 int /*<<< orphan*/  KOBJ_CHANGE ; 
 unsigned int LM_RD_SUCCESS ; 
 int /*<<< orphan*/  kobject_uevent_env (int /*<<< orphan*/ *,int /*<<< orphan*/ ,char**) ; 
 int /*<<< orphan*/  sprintf (char*,char*,...) ; 

__attribute__((used)) static void gfs2_recovery_done(struct gfs2_sbd *sdp, unsigned int jid,
                               unsigned int message)
{
	char env_jid[20];
	char env_status[20];
	char *envp[] = { env_jid, env_status, NULL };
	struct lm_lockstruct *ls = &sdp->sd_lockstruct;
        ls->ls_recover_jid_done = jid;
        ls->ls_recover_jid_status = message;
	sprintf(env_jid, "JID=%d", jid);
	sprintf(env_status, "RECOVERY=%s",
		message == LM_RD_SUCCESS ? "Done" : "Failed");
        kobject_uevent_env(&sdp->sd_kobj, KOBJ_CHANGE, envp);
}