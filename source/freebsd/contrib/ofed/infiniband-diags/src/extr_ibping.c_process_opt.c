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
 int /*<<< orphan*/  AF_INET6 ; 
 void* count ; 
 int /*<<< orphan*/  dgid ; 
 int /*<<< orphan*/  flood ; 
 int /*<<< orphan*/  ibdiag_show_usage () ; 
 int /*<<< orphan*/  inet_pton (int /*<<< orphan*/ ,char*,int /*<<< orphan*/ *) ; 
 void* oui ; 
 int /*<<< orphan*/  printf (char*) ; 
 int /*<<< orphan*/  server ; 
 void* strtoul (char*,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int with_grh ; 

__attribute__((used)) static int process_opt(void *context, int ch, char *optarg)
{
	switch (ch) {
	case 'c':
		count = strtoul(optarg, 0, 0);
		break;
	case 'f':
		flood++;
		break;
	case 'o':
		oui = strtoul(optarg, 0, 0);
		break;
	case 'S':
		server++;
		break;
	case 25:
		if (!inet_pton(AF_INET6, optarg, &dgid)) {
			printf("dgid format is wrong!\n");
			ibdiag_show_usage();
			return 1;
		}
		with_grh = 1;
		break;
	default:
		return -1;
	}
	return 0;
}