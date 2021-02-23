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
typedef  int /*<<< orphan*/  va_list ;

/* Variables and functions */
 int /*<<< orphan*/  fflush (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  fprintf (int /*<<< orphan*/ ,char*,...) ; 
 int /*<<< orphan*/  stderr ; 
 int /*<<< orphan*/  strcat (char*,char*) ; 
 char* strcpy (char*,char const*) ; 
 int strlen (char const*) ; 
 int /*<<< orphan*/  vsprintf (char*,char const*,int /*<<< orphan*/ ) ; 

__attribute__((used)) static
void ConsoleErrorHandler(const char* module, const char* fmt, va_list ap)
{
    char e[512] = { '\0' };

    if (module != NULL) {
        if (strlen(module) < 500)
               strcat(strcpy(e, module), ": ");
    }

    vsprintf(e+strlen(e), fmt, ap);
    strcat(e, ".");
    fprintf(stderr, "\nError");
    fprintf(stderr, " %s\n", e);
    fflush(stderr);
}