#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_2__   TYPE_1__ ;

/* Type definitions */
struct TYPE_2__ {char* grouping; } ;

/* Variables and functions */
 int /*<<< orphan*/  asprintf (char**,char*,...) ; 
 int /*<<< orphan*/  fprintf (int /*<<< orphan*/ ,char*) ; 
 int /*<<< orphan*/  free (char*) ; 
 TYPE_1__ numeric ; 
 int /*<<< orphan*/  stderr ; 

void
add_numeric_group(int n)
{
	char *s;

	if (numeric.grouping == NULL) {
		(void) asprintf(&s, "%d", n);
	} else {
		(void) asprintf(&s, "%s;%d", numeric.grouping, n);
	}
	if (s == NULL)
		fprintf(stderr, "out of memory");

	free((char *)numeric.grouping);
	numeric.grouping = s;
}