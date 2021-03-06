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
struct uwb_relinquish_request_ie {int /*<<< orphan*/  relinquish_req_control; } ;

/* Variables and functions */
 int le16_to_cpu (int /*<<< orphan*/ ) ; 

__attribute__((used)) static inline int uwb_ie_relinquish_req_reason_code(struct uwb_relinquish_request_ie *ie)
{
	return (le16_to_cpu(ie->relinquish_req_control) >> 0) & 0xf;
}