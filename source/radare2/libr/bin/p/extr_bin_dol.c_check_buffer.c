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
typedef  int /*<<< orphan*/  ut8 ;
typedef  int /*<<< orphan*/  tmp ;
typedef  int /*<<< orphan*/  RBuffer ;

/* Variables and functions */
 int /*<<< orphan*/  memcmp (int /*<<< orphan*/ *,char*,int) ; 
 int r_buf_read_at (int /*<<< orphan*/ *,int,int /*<<< orphan*/ *,int) ; 

__attribute__((used)) static bool check_buffer(RBuffer *buf) {
	ut8 tmp[6];
	int r = r_buf_read_at (buf, 0, tmp, sizeof (tmp));
	bool one = r == sizeof (tmp) && !memcmp (tmp, "\x00\x00\x01\x00\x00\x00", sizeof (tmp));
	if (one) {
		int r = r_buf_read_at (buf, 6, tmp, sizeof (tmp));
		if (r != 6) {
			return false;
		}
		return sizeof (tmp) && !memcmp (tmp, "\x00\x00\x00\x00\x00\x00", sizeof (tmp));
	}
	return false;
}