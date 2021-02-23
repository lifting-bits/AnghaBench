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
 scalar_t__ IS_HIGHBIT_SET (unsigned char const) ; 
 int pg_ascii_dsplen (unsigned char const*) ; 

__attribute__((used)) static int
pg_sjis_dsplen(const unsigned char *s)
{
	int			len;

	if (*s >= 0xa1 && *s <= 0xdf)
		len = 1;				/* 1 byte kana? */
	else if (IS_HIGHBIT_SET(*s))
		len = 2;				/* kanji? */
	else
		len = pg_ascii_dsplen(s);	/* should be ASCII */
	return len;
}