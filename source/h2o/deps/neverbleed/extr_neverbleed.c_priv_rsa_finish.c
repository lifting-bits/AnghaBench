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
struct st_neverbleed_thread_data_t {int /*<<< orphan*/  fd; } ;
struct st_neverbleed_rsa_exdata_t {int /*<<< orphan*/  key_index; } ;
struct expbuf_t {int /*<<< orphan*/ * member_0; } ;
typedef  int /*<<< orphan*/  RSA ;

/* Variables and functions */
 int /*<<< orphan*/  dief (char*) ; 
 scalar_t__ errno ; 
 int /*<<< orphan*/  expbuf_dispose (struct expbuf_t*) ; 
 int /*<<< orphan*/  expbuf_push_num (struct expbuf_t*,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  expbuf_push_str (struct expbuf_t*,char*) ; 
 scalar_t__ expbuf_read (struct expbuf_t*,int /*<<< orphan*/ ) ; 
 scalar_t__ expbuf_shift_num (struct expbuf_t*,size_t*) ; 
 scalar_t__ expbuf_write (struct expbuf_t*,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  get_privsep_data (int /*<<< orphan*/ *,struct st_neverbleed_rsa_exdata_t**,struct st_neverbleed_thread_data_t**) ; 

__attribute__((used)) static int priv_rsa_finish(RSA *rsa)
{
    struct st_neverbleed_rsa_exdata_t *exdata;
    struct st_neverbleed_thread_data_t *thdata;

    get_privsep_data(rsa, &exdata, &thdata);

    struct expbuf_t buf = {NULL};
    size_t ret;

    expbuf_push_str(&buf, "del_rsa_key");
    expbuf_push_num(&buf, exdata->key_index);
    if (expbuf_write(&buf, thdata->fd) != 0)
        dief(errno != 0 ? "write error" : "connection closed by daemon");
    expbuf_dispose(&buf);

    if (expbuf_read(&buf, thdata->fd) != 0)
        dief(errno != 0 ? "read error" : "connection closed by daemon");
    if (expbuf_shift_num(&buf, &ret) != 0) {
        errno = 0;
        dief("failed to parse response");
    }
    expbuf_dispose(&buf);

    return (int)ret;
}