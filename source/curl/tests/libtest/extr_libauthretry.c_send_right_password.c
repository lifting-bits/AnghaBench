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
typedef  int /*<<< orphan*/  CURLcode ;
typedef  int /*<<< orphan*/  CURL ;

/* Variables and functions */
 int /*<<< orphan*/  send_request (int /*<<< orphan*/ *,char const*,int,long,char*) ; 

__attribute__((used)) static CURLcode send_right_password(CURL *curl, const char *url, int seq,
                                    long auth_scheme)
{
    return send_request(curl, url, seq, auth_scheme, "testuser:testpass");
}