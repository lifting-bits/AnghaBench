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
struct optioninfo {int dummy; } ;

/* Variables and functions */
 struct optioninfo const* find (char const**,char*,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  oc_long ; 

const struct optioninfo *opt_findl(const char *opt) { return find(&opt,"--",oc_long); }