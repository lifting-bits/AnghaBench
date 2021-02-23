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
 scalar_t__ echo ; 
 int /*<<< orphan*/  size_str (char*,int,int) ; 
 int /*<<< orphan*/  size_to_count (int) ; 
 int /*<<< orphan*/  snprintf (int /*<<< orphan*/ ,int,char*,char*) ; 
 int /*<<< orphan*/  test_name ; 
 int /*<<< orphan*/  transfer_count ; 
 int transfer_size ; 

__attribute__((used)) static void init_bandwidth_test(int size)
{
	char sstr[5];

	size_str(sstr, sizeof sstr, size);
	snprintf(test_name, sizeof test_name, "%s_bw", sstr);
	transfer_size = size;
	transfer_count = size_to_count(transfer_size);
	echo = 0;
}