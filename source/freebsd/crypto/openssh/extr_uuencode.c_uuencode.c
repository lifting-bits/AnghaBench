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
typedef  int /*<<< orphan*/  u_int ;
typedef  int /*<<< orphan*/  u_char ;

/* Variables and functions */
 int __b64_ntop (int /*<<< orphan*/  const*,int /*<<< orphan*/ ,char*,size_t) ; 

int
uuencode(const u_char *src, u_int srclength,
    char *target, size_t targsize)
{
	return __b64_ntop(src, srclength, target, targsize);
}