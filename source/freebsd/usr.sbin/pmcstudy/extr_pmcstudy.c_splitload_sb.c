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
struct counters {double* vals; double sum; } ;

/* Variables and functions */
 struct counters* find_counter (struct counters*,char*) ; 
 int printf (char*,double) ; 

__attribute__((used)) static int
splitload_sb(struct counters *cpu, int pos)
{
	int ret;
	struct counters *mem;
	struct counters *unhalt;
	double con, un, memd, res;
/*  4  - (MEM_UOP_RETIRED.SPLIT_LOADS * 5) / CPU_CLK_UNHALTED.THREAD_P (thresh >= .1)*/

	con = 5.0;
	unhalt = find_counter(cpu, "CPU_CLK_UNHALTED.THREAD_P");
	mem = find_counter(cpu, "MEM_UOP_RETIRED.SPLIT_LOADS");
	if (pos != -1) {
		memd = mem->vals[pos] * 1.0;
		un = unhalt->vals[pos] * 1.0;
	} else {
		memd = mem->sum * 1.0;
		un = unhalt->sum * 1.0;
	}
	res = (memd * con)/un;
	ret = printf("%1.3f", res);
	return(ret);
}