#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_5__   TYPE_2__ ;
typedef  struct TYPE_4__   TYPE_1__ ;

/* Type definitions */
struct dictEntry {int dummy; } ;
struct TYPE_4__ {int /*<<< orphan*/  id; } ;
typedef  TYPE_1__ job ;
struct TYPE_5__ {int /*<<< orphan*/  jobs; } ;

/* Variables and functions */
 struct dictEntry* dictFind (int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 void* dictGetVal (struct dictEntry*) ; 
 TYPE_2__ server ; 

void *jobGetAssociatedValue(job *j) {
    struct dictEntry *de = dictFind(server.jobs, j->id);
    return de ? dictGetVal(de) : NULL;
}