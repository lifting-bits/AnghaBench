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
typedef  scalar_t__ u_int ;
struct utf8_data {int /*<<< orphan*/  have; scalar_t__ width; } ;
typedef  enum utf8_state { ____Placeholder_utf8_state } utf8_state ;

/* Variables and functions */
 int UTF8_DONE ; 
 int UTF8_MORE ; 
 char* format_skip (char const*,char*) ; 
 int utf8_append (struct utf8_data*,char const) ; 
 int utf8_open (struct utf8_data*,char const) ; 

u_int
format_width(const char *expanded)
{
	const char		*cp, *end;
	u_int			 width = 0;
	struct utf8_data	 ud;
	enum utf8_state		 more;

	cp = expanded;
	while (*cp != '\0') {
		if (cp[0] == '#' && cp[1] == '[') {
			end = format_skip(cp + 2, "]");
			if (end == NULL)
				return 0;
			cp = end + 1;
		} else if ((more = utf8_open(&ud, *cp)) == UTF8_MORE) {
			while (*++cp != '\0' && more == UTF8_MORE)
				more = utf8_append(&ud, *cp);
			if (more == UTF8_DONE)
				width += ud.width;
			else
				cp -= ud.have;
		} else if (*cp > 0x1f && *cp < 0x7f) {
			width++;
			cp++;
		} else
			cp++;
	}
	return (width);
}