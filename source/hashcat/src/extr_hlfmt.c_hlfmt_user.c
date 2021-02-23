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
typedef  int u32 ;
typedef  int /*<<< orphan*/  hashcat_ctx_t ;

/* Variables and functions */
#define  HLFMT_HASHCAT 131 
#define  HLFMT_PASSWD 130 
#define  HLFMT_PWDUMP 129 
#define  HLFMT_SHADOW 128 
 int /*<<< orphan*/  hlfmt_user_hashcat (int /*<<< orphan*/ *,char*,int const,char**,int*) ; 
 int /*<<< orphan*/  hlfmt_user_passwd (int /*<<< orphan*/ *,char*,int const,char**,int*) ; 
 int /*<<< orphan*/  hlfmt_user_pwdump (int /*<<< orphan*/ *,char*,int const,char**,int*) ; 
 int /*<<< orphan*/  hlfmt_user_shadow (int /*<<< orphan*/ *,char*,int const,char**,int*) ; 

void hlfmt_user (hashcat_ctx_t *hashcat_ctx, u32 hashfile_format, char *line_buf, const int line_len, char **userbuf_pos, int *userbuf_len)
{
  switch (hashfile_format)
  {
    case HLFMT_HASHCAT: hlfmt_user_hashcat (hashcat_ctx, line_buf, line_len, userbuf_pos, userbuf_len); break;
    case HLFMT_PWDUMP:  hlfmt_user_pwdump  (hashcat_ctx, line_buf, line_len, userbuf_pos, userbuf_len); break;
    case HLFMT_PASSWD:  hlfmt_user_passwd  (hashcat_ctx, line_buf, line_len, userbuf_pos, userbuf_len); break;
    case HLFMT_SHADOW:  hlfmt_user_shadow  (hashcat_ctx, line_buf, line_len, userbuf_pos, userbuf_len); break;
  }
}