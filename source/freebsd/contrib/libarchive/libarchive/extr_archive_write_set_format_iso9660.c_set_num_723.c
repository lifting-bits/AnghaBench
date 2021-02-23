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
typedef  int /*<<< orphan*/  uint16_t ;

/* Variables and functions */
 int /*<<< orphan*/  archive_be16enc (unsigned char*,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  archive_le16enc (unsigned char*,int /*<<< orphan*/ ) ; 

__attribute__((used)) static void
set_num_723(unsigned char *p, uint16_t value)
{
	archive_le16enc(p, value);
	archive_be16enc(p+2, value);
}