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
typedef  char u_char ;
struct winentry {int weCnt; int weChksum; int /*<<< orphan*/  wePart3; int /*<<< orphan*/  wePart2; int /*<<< orphan*/  wePart1; scalar_t__ weReserved2; scalar_t__ weReserved1; int /*<<< orphan*/  weAttributes; } ;

/* Variables and functions */
 int /*<<< orphan*/  ATTR_WIN95 ; 
 int WIN_CHARS ; 
 int WIN_LAST ; 
 int WIN_MAXLEN ; 
 int char8ucs2str (char const*,size_t,int /*<<< orphan*/ *,int) ; 
 int /*<<< orphan*/  memcpy (int /*<<< orphan*/ ,int /*<<< orphan*/ *,int) ; 
 int /*<<< orphan*/  memset (struct winentry*,int,int) ; 
 int /*<<< orphan*/  ucs2pad (int /*<<< orphan*/ *,int,int) ; 

int
unix2winfn(const u_char *un, size_t unlen, struct winentry *wep, int cnt,
    int chksum)
{
	uint16_t wn[WIN_MAXLEN], *p;
	int i, len;
	const u_char *cp;

	/*
	 * Drop trailing blanks and dots
	 */
	for (cp = un + unlen; unlen > 0; unlen--)
		if (*--cp != ' ' && *cp != '.')
			break;

	/*
	 * Offset of this entry
	 */
	i = (cnt - 1) * WIN_CHARS;

	/*
	 * Translate UNIX name to ucs-2
	 */
	len = char8ucs2str(un, unlen, wn, WIN_MAXLEN);
	ucs2pad(wn, len, WIN_MAXLEN);

	/*
	 * Initialize winentry to some useful default
	 */
	memset(wep, 0xff, sizeof(*wep));
	wep->weCnt = cnt;
	wep->weAttributes = ATTR_WIN95;
	wep->weReserved1 = 0;
	wep->weChksum = chksum;
	wep->weReserved2 = 0;

	/*
	 * Store name segment into directory entry
	 */
	p = &wn[i];
	memcpy(wep->wePart1, p, sizeof(wep->wePart1));
	p += sizeof(wep->wePart1) / sizeof(*p);
	memcpy(wep->wePart2, p, sizeof(wep->wePart2));
	p += sizeof(wep->wePart2) / sizeof(*p);
	memcpy(wep->wePart3, p, sizeof(wep->wePart3));

	if (len > i + WIN_CHARS)
		return 1;

	wep->weCnt |= WIN_LAST;
	return 0;
}