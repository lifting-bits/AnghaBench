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
 int /*<<< orphan*/  CONF ; 
 int /*<<< orphan*/  CONF_module_add (char*,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  OSSL_TRACE (int /*<<< orphan*/ ,char*) ; 
 int /*<<< orphan*/  provider_conf_deinit ; 
 int /*<<< orphan*/  provider_conf_init ; 

void ossl_provider_add_conf_module(void)
{
    OSSL_TRACE(CONF, "Adding config module 'providers'\n");
    CONF_module_add("providers", provider_conf_init, provider_conf_deinit);
}