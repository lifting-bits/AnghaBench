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
 int lib80211_get80211 (int,int /*<<< orphan*/ ,int,void*,int) ; 
 int /*<<< orphan*/  name ; 

__attribute__((used)) static int
get80211(int s, int type, void *data, int len)
{

	return (lib80211_get80211(s, name, type, data, len));
}