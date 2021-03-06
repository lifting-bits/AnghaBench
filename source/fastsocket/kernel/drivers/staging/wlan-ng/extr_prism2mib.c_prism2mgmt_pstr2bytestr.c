#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_6__   TYPE_2__ ;
typedef  struct TYPE_5__   TYPE_1__ ;

/* Type definitions */
typedef  int /*<<< orphan*/  u16 ;
struct TYPE_5__ {scalar_t__ len; int /*<<< orphan*/  data; } ;
typedef  TYPE_1__ p80211pstrd_t ;
struct TYPE_6__ {int /*<<< orphan*/  data; int /*<<< orphan*/  len; } ;
typedef  TYPE_2__ hfa384x_bytestr_t ;

/* Variables and functions */
 int /*<<< orphan*/  cpu_to_le16 (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  memcpy (int /*<<< orphan*/ ,int /*<<< orphan*/ ,scalar_t__) ; 

void prism2mgmt_pstr2bytestr(hfa384x_bytestr_t *bytestr, p80211pstrd_t *pstr)
{
	bytestr->len = cpu_to_le16((u16) (pstr->len));
	memcpy(bytestr->data, pstr->data, pstr->len);
}