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
struct perf_stat {int dummy; } ;
struct perf_evsel {int /*<<< orphan*/ * priv; } ;

/* Variables and functions */
 int ENOMEM ; 
 int /*<<< orphan*/ * zalloc (int) ; 

__attribute__((used)) static int perf_evsel__alloc_stat_priv(struct perf_evsel *evsel)
{
	evsel->priv = zalloc(sizeof(struct perf_stat));
	return evsel->priv == NULL ? -ENOMEM : 0;
}