#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_4__   TYPE_2__ ;
typedef  struct TYPE_3__   TYPE_1__ ;

/* Type definitions */
typedef  int /*<<< orphan*/  tBTA_HF_CLIENT_AT_CB ;
struct TYPE_3__ {int /*<<< orphan*/  at_cb; } ;
struct TYPE_4__ {TYPE_1__ scb; } ;

/* Variables and functions */
 int /*<<< orphan*/  bta_hf_client_at_reset () ; 
 TYPE_2__ bta_hf_client_cb ; 
 int /*<<< orphan*/  memset (int /*<<< orphan*/ *,int /*<<< orphan*/ ,int) ; 

void bta_hf_client_at_init(void)
{
    memset(&bta_hf_client_cb.scb.at_cb, 0, sizeof(tBTA_HF_CLIENT_AT_CB));
    bta_hf_client_at_reset();
}