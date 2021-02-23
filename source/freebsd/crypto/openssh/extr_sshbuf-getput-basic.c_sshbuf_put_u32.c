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
typedef  int /*<<< orphan*/  u_int32_t ;
typedef  int /*<<< orphan*/  u_char ;
struct sshbuf {int dummy; } ;

/* Variables and functions */
 int /*<<< orphan*/  POKE_U32 (int /*<<< orphan*/ *,int /*<<< orphan*/ ) ; 
 int sshbuf_reserve (struct sshbuf*,int,int /*<<< orphan*/ **) ; 

int
sshbuf_put_u32(struct sshbuf *buf, u_int32_t val)
{
	u_char *p;
	int r;

	if ((r = sshbuf_reserve(buf, 4, &p)) < 0)
		return r;
	POKE_U32(p, val);
	return 0;
}