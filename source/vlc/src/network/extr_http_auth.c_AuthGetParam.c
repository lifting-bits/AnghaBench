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
 int /*<<< orphan*/  sprintf (char*,char*,char const*) ; 
 char* strchr (char const*,char) ; 
 char* strdup (char const*) ; 
 int strlen (char const*) ; 
 char* strndup (char const*,int) ; 
 char* strstr (char const*,char*) ; 

__attribute__((used)) static char *AuthGetParam( const char *psz_header, const char *psz_param )
{
    char psz_what[strlen(psz_param)+3];
    sprintf( psz_what, "%s=\"", psz_param );
    psz_header = strstr( psz_header, psz_what );
    if ( psz_header )
    {
        const char *psz_end;
        psz_header += strlen( psz_what );
        psz_end = strchr( psz_header, '"' );
        if ( !psz_end ) /* Invalid since we should have a closing quote */
            return strdup( psz_header );
        return strndup( psz_header, psz_end - psz_header );
    }
    else
    {
        return NULL;
    }
}