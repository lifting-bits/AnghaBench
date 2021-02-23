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
typedef  int /*<<< orphan*/  krb5_context ;

/* Variables and functions */
 int /*<<< orphan*/  args ; 
 int /*<<< orphan*/  client_usage (int,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int common_setup (int /*<<< orphan*/ *,int*,char**,int /*<<< orphan*/  (*) (int,int /*<<< orphan*/ ,int /*<<< orphan*/ )) ; 
 int /*<<< orphan*/  num_args ; 

int
client_setup(krb5_context *context, int *argc, char **argv)
{
    int optind = *argc;
    int port = common_setup(context, &optind, argv, client_usage);
    if(*argc - optind != 1)
	client_usage(1, args, num_args);
    *argc = optind;
    return port;
}