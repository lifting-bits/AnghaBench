#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_4__   TYPE_1__ ;

/* Type definitions */
typedef  TYPE_1__* hx509_error ;
struct TYPE_4__ {struct TYPE_4__* msg; struct TYPE_4__* next; } ;

/* Variables and functions */
 int /*<<< orphan*/  free (TYPE_1__*) ; 

__attribute__((used)) static void
free_error_string(hx509_error msg)
{
    while(msg) {
	hx509_error m2 = msg->next;
	free(msg->msg);
	free(msg);
	msg = m2;
    }
}