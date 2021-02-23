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
struct format_tree {int dummy; } ;

/* Variables and functions */
 char* format_expand1 (struct format_tree*,char const*,int) ; 

char *
format_expand_time(struct format_tree *ft, const char *fmt)
{
	return (format_expand1(ft, fmt, 1));
}