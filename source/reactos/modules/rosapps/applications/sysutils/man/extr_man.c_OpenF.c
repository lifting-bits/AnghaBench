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
 int /*<<< orphan*/  AnalyzeFile () ; 
 int MAXLINE ; 
 int OpenFlag ; 
 int /*<<< orphan*/ * fopen (int /*<<< orphan*/ ,char*) ; 
 int /*<<< orphan*/  free (char*) ; 
 scalar_t__ malloc (int) ; 
 int /*<<< orphan*/ * manfile ; 
 int /*<<< orphan*/  manpath ; 
 int /*<<< orphan*/  strcat (char*,char*) ; 
 int /*<<< orphan*/  strcpy (char*,int /*<<< orphan*/ ) ; 

int
OpenF(char* name)
{
    int retval=0;
    char *manpath_local=(char*)malloc(sizeof(char)*MAXLINE);

    strcpy(manpath_local, manpath); //save mandir value

    if((manfile=fopen((strcat(manpath_local,name)),"r"))!=NULL)
     {
      OpenFlag=1;
      AnalyzeFile();
     }
    else
     retval=-1;

    free(manpath_local);
    return retval;
}