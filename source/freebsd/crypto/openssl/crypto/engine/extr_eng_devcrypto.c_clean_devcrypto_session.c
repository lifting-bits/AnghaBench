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
struct session_op {int /*<<< orphan*/  ses; } ;

/* Variables and functions */
 int /*<<< orphan*/  CIOCFSESSION ; 
 int /*<<< orphan*/  SYS_F_IOCTL ; 
 int /*<<< orphan*/  SYSerr (int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  cfd ; 
 int /*<<< orphan*/  errno ; 
 scalar_t__ ioctl (int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  memset (struct session_op*,int /*<<< orphan*/ ,int) ; 

__attribute__((used)) static int clean_devcrypto_session(struct session_op *sess) {
    if (ioctl(cfd, CIOCFSESSION, &sess->ses) < 0) {
        SYSerr(SYS_F_IOCTL, errno);
        return 0;
    }
    memset(sess, 0, sizeof(struct session_op));
    return 1;
}