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
 int /*<<< orphan*/  mp_uos_dupterm_tx_strn (char const*,size_t) ; 
 int write (int,char const*,size_t) ; 

void mp_hal_stdout_tx_strn(const char *str, size_t len) {
    int ret = write(1, str, len);
    mp_uos_dupterm_tx_strn(str, len);
    (void)ret; // to suppress compiler warning
}