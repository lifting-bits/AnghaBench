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
typedef  int /*<<< orphan*/  URLContext ;

/* Variables and functions */
 int ff_http_do_new_request2 (int /*<<< orphan*/ *,char const*,int /*<<< orphan*/ *) ; 

int ff_http_do_new_request(URLContext *h, const char *uri) {
    return ff_http_do_new_request2(h, uri, NULL);
}