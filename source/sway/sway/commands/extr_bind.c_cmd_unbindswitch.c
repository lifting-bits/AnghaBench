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
struct cmd_results {int dummy; } ;

/* Variables and functions */
 struct cmd_results* cmd_bind_or_unbind_switch (int,char**,int) ; 

struct cmd_results *cmd_unbindswitch(int argc, char **argv) {
	return cmd_bind_or_unbind_switch(argc, argv, true);
}