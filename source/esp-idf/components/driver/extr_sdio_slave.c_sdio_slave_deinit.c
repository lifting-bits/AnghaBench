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
typedef  scalar_t__ esp_err_t ;
struct TYPE_2__ {int /*<<< orphan*/ * intr_handle; } ;

/* Variables and functions */
 scalar_t__ ESP_OK ; 
 int /*<<< orphan*/  assert (int) ; 
 TYPE_1__ context ; 
 int /*<<< orphan*/  deinit_context () ; 
 scalar_t__ esp_intr_free (int /*<<< orphan*/ *) ; 

void sdio_slave_deinit(void)
{
    esp_err_t ret = esp_intr_free(context.intr_handle);
    assert(ret==ESP_OK);
    context.intr_handle = NULL;
    deinit_context();
}