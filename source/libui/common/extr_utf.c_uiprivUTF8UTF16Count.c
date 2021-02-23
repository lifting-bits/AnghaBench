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
typedef  int /*<<< orphan*/  uint32_t ;
typedef  int /*<<< orphan*/  uint16_t ;

/* Variables and functions */
 scalar_t__ uiprivUTF16EncodeRune (int /*<<< orphan*/ ,int /*<<< orphan*/ *) ; 
 char* uiprivUTF8DecodeRune (char const*,size_t,int /*<<< orphan*/ *) ; 

size_t uiprivUTF8UTF16Count(const char *s, size_t nElem)
{
	size_t len;
	uint32_t rune;
	uint16_t encoded[2];

	if (nElem != 0) {
		const char *t, *u;

		len = 0;
		t = s;
		while (nElem != 0) {
			u = uiprivUTF8DecodeRune(t, nElem, &rune);
			len += uiprivUTF16EncodeRune(rune, encoded);
			nElem -= u - t;
			t = u;
		}
		return len;
	}
	len = 0;
	while (*s) {
		s = uiprivUTF8DecodeRune(s, nElem, &rune);
		len += uiprivUTF16EncodeRune(rune, encoded);
	}
	return len;
}