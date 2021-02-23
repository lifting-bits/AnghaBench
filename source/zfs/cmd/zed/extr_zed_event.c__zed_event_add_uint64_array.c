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
typedef  int /*<<< orphan*/  zed_strings_t ;
typedef  size_t uint_t ;
typedef  scalar_t__ uint64_t ;
typedef  int /*<<< orphan*/  u_longlong_t ;
typedef  int /*<<< orphan*/  nvpair_t ;
typedef  int /*<<< orphan*/  buf ;

/* Variables and functions */
 scalar_t__ DATA_TYPE_UINT64_ARRAY ; 
 int MAXBUF ; 
 int _zed_event_add_array_err (scalar_t__,char const*) ; 
 int _zed_event_add_var (scalar_t__,int /*<<< orphan*/ *,char const*,char const*,char*,char*) ; 
 scalar_t__ _zed_event_value_is_hex (char const*) ; 
 int /*<<< orphan*/  assert (int) ; 
 char* nvpair_name (int /*<<< orphan*/ *) ; 
 scalar_t__ nvpair_type (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  nvpair_value_uint64_array (int /*<<< orphan*/ *,scalar_t__**,size_t*) ; 
 int snprintf (char*,int,char const*,int /*<<< orphan*/ ) ; 

__attribute__((used)) static int
_zed_event_add_uint64_array(uint64_t eid, zed_strings_t *zsp,
    const char *prefix, nvpair_t *nvp)
{
	char buf[MAXBUF];
	int buflen = sizeof (buf);
	const char *name;
	const char *fmt;
	uint64_t *u64p;
	uint_t nelem;
	uint_t i;
	char *p;
	int n;

	assert((nvp != NULL) && (nvpair_type(nvp) == DATA_TYPE_UINT64_ARRAY));

	name = nvpair_name(nvp);
	fmt = _zed_event_value_is_hex(name) ? "0x%.16llX " : "%llu ";
	(void) nvpair_value_uint64_array(nvp, &u64p, &nelem);
	for (i = 0, p = buf; (i < nelem) && (buflen > 0); i++) {
		n = snprintf(p, buflen, fmt, (u_longlong_t)u64p[i]);
		if ((n < 0) || (n >= buflen))
			return (_zed_event_add_array_err(eid, name));
		p += n;
		buflen -= n;
	}
	if (nelem > 0)
		*--p = '\0';

	return (_zed_event_add_var(eid, zsp, prefix, name, "%s", buf));
}