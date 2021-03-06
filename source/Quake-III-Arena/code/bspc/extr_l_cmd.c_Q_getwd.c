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
 int /*<<< orphan*/  getcwd (char*,int) ; 
 int /*<<< orphan*/  getwd (char*) ; 
 int /*<<< orphan*/  strcat (char*,char*) ; 

void Q_getwd (char *out)
{
#if defined(WIN32) || defined(_WIN32)
   getcwd (out, 256);
   strcat (out, "\\");
#else
   getwd(out);
   strcat(out, "/");
#endif
}