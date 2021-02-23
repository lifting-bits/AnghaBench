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
struct vlc_http_msg {int dummy; } ;

/* Variables and functions */
 int /*<<< orphan*/  assert (int) ; 
 int /*<<< orphan*/  strcmp (char const*,char*) ; 
 char* vlc_http_msg_get_authority (struct vlc_http_msg const*) ; 
 char* vlc_http_msg_get_header (struct vlc_http_msg const*,char*) ; 
 char* vlc_http_msg_get_method (struct vlc_http_msg const*) ; 
 char* vlc_http_msg_get_path (struct vlc_http_msg const*) ; 
 char* vlc_http_msg_get_scheme (struct vlc_http_msg const*) ; 
 int vlc_http_msg_get_status (struct vlc_http_msg const*) ; 

__attribute__((used)) static void check_resp(const struct vlc_http_msg *m)
{
    const char *str;

    assert(vlc_http_msg_get_status(m) == 200);
    str = vlc_http_msg_get_method(m);
    assert(str == NULL);
    str = vlc_http_msg_get_scheme(m);
    assert(str == NULL);
    str = vlc_http_msg_get_authority(m);
    assert(str == NULL);
    str = vlc_http_msg_get_path(m);
    assert(str == NULL);

    str = vlc_http_msg_get_header(m, "Cache-Control");
    assert(str != NULL && !strcmp(str, "private"));
    str = vlc_http_msg_get_header(m, "Date");
    assert(str != NULL && !strcmp(str, "Mon, 21 Oct 2013 20:13:22 GMT"));
    str = vlc_http_msg_get_header(m, "Location");
    assert(str != NULL && !strcmp(str, "https://www.example.com"));
    str = vlc_http_msg_get_header(m, "Content-Encoding");
    assert(str != NULL && !strcmp(str, "gzip"));
    str = vlc_http_msg_get_header(m, "Set-Cookie");
    assert(str != NULL && !strcmp(str, "foo=ASDJKHQKBZXOQWEOPIUAXQWEOIU; "
                                  "max-age=3600; version=1"));

    str = vlc_http_msg_get_header(m, "Custom-Key");
    assert(str == NULL);
}