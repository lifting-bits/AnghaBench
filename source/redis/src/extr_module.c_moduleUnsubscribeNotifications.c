#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_7__   TYPE_2__ ;
typedef  struct TYPE_6__   TYPE_1__ ;

/* Type definitions */
struct TYPE_6__ {TYPE_2__* value; } ;
typedef  TYPE_1__ listNode ;
typedef  int /*<<< orphan*/  listIter ;
struct TYPE_7__ {int /*<<< orphan*/ * module; } ;
typedef  TYPE_2__ RedisModuleKeyspaceSubscriber ;
typedef  int /*<<< orphan*/  RedisModule ;

/* Variables and functions */
 int /*<<< orphan*/  listDelNode (int /*<<< orphan*/ ,TYPE_1__*) ; 
 TYPE_1__* listNext (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  listRewind (int /*<<< orphan*/ ,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  moduleKeyspaceSubscribers ; 
 int /*<<< orphan*/  zfree (TYPE_2__*) ; 

void moduleUnsubscribeNotifications(RedisModule *module) {
    listIter li;
    listNode *ln;
    listRewind(moduleKeyspaceSubscribers,&li);
    while((ln = listNext(&li))) {
        RedisModuleKeyspaceSubscriber *sub = ln->value;
        if (sub->module == module) {
            listDelNode(moduleKeyspaceSubscribers, ln);
            zfree(sub);
        }
    }
}