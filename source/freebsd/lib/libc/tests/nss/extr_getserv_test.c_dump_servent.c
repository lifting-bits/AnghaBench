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
struct servent {int dummy; } ;
typedef  int /*<<< orphan*/  buffer ;

/* Variables and functions */
 int /*<<< orphan*/  printf (char*,...) ; 
 int /*<<< orphan*/  sdump_servent (struct servent*,char*,int) ; 

__attribute__((used)) static void
dump_servent(struct servent *result)
{
	if (result != NULL) {
		char buffer[1024];
		sdump_servent(result, buffer, sizeof(buffer));
		printf("%s\n", buffer);
	} else
		printf("(null)\n");
}