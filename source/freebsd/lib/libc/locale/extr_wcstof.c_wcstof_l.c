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
typedef  int /*<<< orphan*/  wchar_t ;
typedef  int /*<<< orphan*/  mbstate_t ;
typedef  int /*<<< orphan*/  locale_t ;

/* Variables and functions */
 int /*<<< orphan*/  FIX_LOCALE (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  free (char*) ; 
 scalar_t__ iswspace_l (int /*<<< orphan*/  const,int /*<<< orphan*/ ) ; 
 char* malloc (size_t) ; 
 float strtof_l (char*,char**,int /*<<< orphan*/ ) ; 
 size_t wcsrtombs_l (char*,int /*<<< orphan*/  const**,size_t,int /*<<< orphan*/ *,int /*<<< orphan*/ ) ; 

float
wcstof_l(const wchar_t * __restrict nptr, wchar_t ** __restrict endptr,
		locale_t locale)
{
	static const mbstate_t initial;
	mbstate_t mbs;
	float val;
	char *buf, *end;
	const wchar_t *wcp;
	size_t len;
	size_t spaces;
	FIX_LOCALE(locale);

	wcp = nptr;
	spaces = 0;
	while (iswspace_l(*wcp, locale)) {
		wcp++;
		spaces++;
	}

	mbs = initial;
	if ((len = wcsrtombs_l(NULL, &wcp, 0, &mbs, locale)) == (size_t)-1) {
		if (endptr != NULL)
			*endptr = (wchar_t *)nptr;
		return (0.0);
	}
	if ((buf = malloc(len + 1)) == NULL) {
		if (endptr != NULL)
			*endptr = (wchar_t *)nptr;
		return (0.0);
	}
	mbs = initial;
	wcsrtombs_l(buf, &wcp, len + 1, &mbs, locale);

	val = strtof_l(buf, &end, locale);

	if (endptr != NULL) {
		*endptr = (wchar_t *)nptr + (end - buf);
		if (buf != end)
			*endptr += spaces;
	}

	free(buf);

	return (val);
}