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
typedef  int /*<<< orphan*/  u_long ;
typedef  int /*<<< orphan*/  FILE ;

/* Variables and functions */
 int COUNTOF (char*) ; 
 int EOF ; 
 int _O_TEXT ; 
 int /*<<< orphan*/ * _fdopen (int /*<<< orphan*/ ,char*) ; 
 int /*<<< orphan*/  atoi (char*) ; 
 int /*<<< orphan*/  fclose (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/ * fdopen (int /*<<< orphan*/ ,char*) ; 
 int /*<<< orphan*/  fflush (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  fprintf (int /*<<< orphan*/ ,char*,char const*) ; 
 int getc (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  open (char*,int) ; 
 int /*<<< orphan*/  setbuf (int /*<<< orphan*/ *,char*) ; 
 int /*<<< orphan*/  stderr ; 
 int /*<<< orphan*/ * stdin ; 

__attribute__((used)) static u_long
getkeyid(
	const char *keyprompt
	)
{
	int c;
	FILE *fi;
	char pbuf[20];
	size_t i;
	size_t ilim;

#ifndef SYS_WINNT
	if ((fi = fdopen(open("/dev/tty", 2), "r")) == NULL)
#else
	if ((fi = _fdopen(open("CONIN$", _O_TEXT), "r")) == NULL)
#endif /* SYS_WINNT */
		fi = stdin;
	else
		setbuf(fi, (char *)NULL);
	fprintf(stderr, "%s", keyprompt); fflush(stderr);
	for (i = 0, ilim = COUNTOF(pbuf) - 1;
	     i < ilim && (c = getc(fi)) != '\n' && c != EOF;
	     )
		pbuf[i++] = (char)c;
	pbuf[i] = '\0';
	if (fi != stdin)
		fclose(fi);

	return (u_long) atoi(pbuf);
}