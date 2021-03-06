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
typedef  int uint16_t ;

/* Variables and functions */
 int /*<<< orphan*/  RECV (char*,char const*,size_t) ; 

__attribute__((used)) static void
recv_data(uint16_t blocknum, const char* contents, size_t contents_len)
{
	char hdr[] = {0, 3, blocknum >> 8, blocknum & 0xFF};
	RECV(hdr, contents, contents_len);
}