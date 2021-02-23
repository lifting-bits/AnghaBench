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

/* Variables and functions */
 int /*<<< orphan*/  EAGAIN ; 
 int /*<<< orphan*/  EINTR ; 
 int /*<<< orphan*/  EOPNOTSUPP ; 
 scalar_t__ ERRNO_IS_DISCONNECT (int) ; 
 scalar_t__ IN_SET (int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  abs (int) ; 

__attribute__((used)) static inline bool ERRNO_IS_ACCEPT_AGAIN(int r) {
        return ERRNO_IS_DISCONNECT(r) ||
                IN_SET(abs(r),
                       EAGAIN,
                       EINTR,
                       EOPNOTSUPP);
}