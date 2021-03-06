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
struct intel_guc {scalar_t__ send; } ;

/* Variables and functions */
 scalar_t__ intel_guc_send_nop ; 

__attribute__((used)) static inline bool guc_communication_enabled(struct intel_guc *guc)
{
	return guc->send != intel_guc_send_nop;
}