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
 int /*<<< orphan*/  php_crypt_extended_init_lock ; 
 int /*<<< orphan*/  tsrm_mutex_free (int /*<<< orphan*/ ) ; 

void php_shutdown_crypt_r()
{
#ifdef ZTS
	tsrm_mutex_free(php_crypt_extended_init_lock);
#endif
}