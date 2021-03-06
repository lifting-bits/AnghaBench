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
struct mddev {int ro; scalar_t__ thread; int /*<<< orphan*/  suspended; int /*<<< orphan*/  recovery; scalar_t__ sync_thread; TYPE_1__* pers; } ;
struct raid_set {struct mddev md; } ;
struct dm_target {struct raid_set* private; } ;
struct TYPE_2__ {int /*<<< orphan*/  sync_request; } ;

/* Variables and functions */
 int EBUSY ; 
 int EINVAL ; 
 int /*<<< orphan*/  MD_RECOVERY_CHECK ; 
 int /*<<< orphan*/  MD_RECOVERY_FROZEN ; 
 int /*<<< orphan*/  MD_RECOVERY_INTR ; 
 int /*<<< orphan*/  MD_RECOVERY_NEEDED ; 
 int /*<<< orphan*/  MD_RECOVERY_RECOVER ; 
 int /*<<< orphan*/  MD_RECOVERY_REQUESTED ; 
 int /*<<< orphan*/  MD_RECOVERY_SYNC ; 
 int /*<<< orphan*/  clear_bit (int /*<<< orphan*/ ,int /*<<< orphan*/ *) ; 
 scalar_t__ decipher_sync_action (struct mddev*,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  md_reap_sync_thread (struct mddev*) ; 
 int /*<<< orphan*/  md_wakeup_thread (scalar_t__) ; 
 int /*<<< orphan*/  set_bit (int /*<<< orphan*/ ,int /*<<< orphan*/ *) ; 
 scalar_t__ st_idle ; 
 int /*<<< orphan*/  strcasecmp (char*,char*) ; 

__attribute__((used)) static int raid_message(struct dm_target *ti, unsigned int argc, char **argv,
			char *result, unsigned maxlen)
{
	struct raid_set *rs = ti->private;
	struct mddev *mddev = &rs->md;

	if (!mddev->pers || !mddev->pers->sync_request)
		return -EINVAL;

	if (!strcasecmp(argv[0], "frozen"))
		set_bit(MD_RECOVERY_FROZEN, &mddev->recovery);
	else
		clear_bit(MD_RECOVERY_FROZEN, &mddev->recovery);

	if (!strcasecmp(argv[0], "idle") || !strcasecmp(argv[0], "frozen")) {
		if (mddev->sync_thread) {
			set_bit(MD_RECOVERY_INTR, &mddev->recovery);
			md_reap_sync_thread(mddev);
		}
	} else if (decipher_sync_action(mddev, mddev->recovery) != st_idle)
		return -EBUSY;
	else if (!strcasecmp(argv[0], "resync"))
		; /* MD_RECOVERY_NEEDED set below */
	else if (!strcasecmp(argv[0], "recover"))
		set_bit(MD_RECOVERY_RECOVER, &mddev->recovery);
	else {
		if (!strcasecmp(argv[0], "check")) {
			set_bit(MD_RECOVERY_CHECK, &mddev->recovery);
			set_bit(MD_RECOVERY_REQUESTED, &mddev->recovery);
			set_bit(MD_RECOVERY_SYNC, &mddev->recovery);
		} else if (!strcasecmp(argv[0], "repair")) {
			set_bit(MD_RECOVERY_REQUESTED, &mddev->recovery);
			set_bit(MD_RECOVERY_SYNC, &mddev->recovery);
		} else
			return -EINVAL;
	}
	if (mddev->ro == 2) {
		/* A write to sync_action is enough to justify
		 * canceling read-auto mode
		 */
		mddev->ro = 0;
		if (!mddev->suspended && mddev->sync_thread)
			md_wakeup_thread(mddev->sync_thread);
	}
	set_bit(MD_RECOVERY_NEEDED, &mddev->recovery);
	if (!mddev->suspended && mddev->thread)
		md_wakeup_thread(mddev->thread);

	return 0;
}