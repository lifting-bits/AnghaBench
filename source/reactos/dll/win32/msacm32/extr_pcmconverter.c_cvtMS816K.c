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
 short C816 (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  TRACE (char*,unsigned char const*,int,unsigned char*) ; 
 int /*<<< orphan*/  W16 (unsigned char*,short) ; 

__attribute__((used)) static	void cvtMS816K(const unsigned char* src, int ns, unsigned char* dst)
{
    short	v;
    TRACE("(%p, %d, %p)\n", src, ns, dst);

    while (ns--) {
	v = C816(*src++);
	W16(dst, v);		dst += 2;
	W16(dst, v);		dst += 2;
    }
}