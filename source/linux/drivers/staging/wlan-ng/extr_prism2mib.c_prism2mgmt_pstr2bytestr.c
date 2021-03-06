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
typedef  int /*<<< orphan*/  u16 ;
struct p80211pstrd {scalar_t__ len; int /*<<< orphan*/  data; } ;
struct hfa384x_bytestr {int /*<<< orphan*/  data; int /*<<< orphan*/  len; } ;

/* Variables and functions */
 int /*<<< orphan*/  cpu_to_le16 (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  memcpy (int /*<<< orphan*/ ,int /*<<< orphan*/ ,scalar_t__) ; 

void prism2mgmt_pstr2bytestr(struct hfa384x_bytestr *bytestr,
			     struct p80211pstrd *pstr)
{
	bytestr->len = cpu_to_le16((u16)(pstr->len));
	memcpy(bytestr->data, pstr->data, pstr->len);
}