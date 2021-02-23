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
 int MB_ICONWARNING ; 
 int MB_OK ; 
 int /*<<< orphan*/  MessageBox (int /*<<< orphan*/ ,char*,char*,int) ; 
 int /*<<< orphan*/  dialog ; 
 int /*<<< orphan*/  free (char*) ; 
 char* vstrmake (int /*<<< orphan*/ *,int /*<<< orphan*/ ) ; 

__attribute__((used)) static int
guiWarning (va_list ap)
{
    char *str = vstrmake (NULL, ap);

    MessageBox (dialog, str, "Warning", MB_ICONWARNING | MB_OK);
    free (str);
    return 0;
}