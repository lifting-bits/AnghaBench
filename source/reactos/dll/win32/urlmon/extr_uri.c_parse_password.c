#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_3__   TYPE_1__ ;

/* Type definitions */
struct TYPE_3__ {char const* password; scalar_t__ scheme_type; int password_len; } ;
typedef  TYPE_1__ parse_data ;
typedef  char WCHAR ;
typedef  int DWORD ;
typedef  int /*<<< orphan*/  BOOL ;

/* Variables and functions */
 int ALLOW_NULL_TERM_PASSWORD ; 
 int /*<<< orphan*/  FALSE ; 
 int /*<<< orphan*/  TRUE ; 
 scalar_t__ URL_SCHEME_UNKNOWN ; 
 int /*<<< orphan*/  check_pct_encoded (char const**) ; 
 scalar_t__ is_auth_delim (char const,int) ; 

__attribute__((used)) static BOOL parse_password(const WCHAR **ptr, parse_data *data, DWORD flags, DWORD extras) {
    data->password = *ptr;

    while(**ptr != '@') {
        if(**ptr == '%') {
            if(!check_pct_encoded(ptr)) {
                if(data->scheme_type != URL_SCHEME_UNKNOWN) {
                    *ptr = data->password;
                    data->password = NULL;
                    return FALSE;
                }
            } else
                continue;
        } else if(extras & ALLOW_NULL_TERM_PASSWORD && !**ptr)
            break;
        else if(is_auth_delim(**ptr, data->scheme_type != URL_SCHEME_UNKNOWN)) {
            *ptr = data->password;
            data->password = NULL;
            return FALSE;
        }

        ++(*ptr);
    }

    data->password_len = *ptr - data->password;
    return TRUE;
}