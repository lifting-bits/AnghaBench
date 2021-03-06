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
struct timer_list {void (* function ) (unsigned long) ;unsigned long data; } ;
struct lock_class_key {int dummy; } ;

/* Variables and functions */
 int /*<<< orphan*/  init_timer_on_stack_key (struct timer_list*,char const*,struct lock_class_key*) ; 
 int /*<<< orphan*/  timer_set_deferrable (struct timer_list*) ; 

void setup_deferrable_timer_on_stack_key(struct timer_list *timer,
					 const char *name,
					 struct lock_class_key *key,
					 void (*function)(unsigned long),
					 unsigned long data)
{
	timer->function = function;
	timer->data = data;
	init_timer_on_stack_key(timer, name, key);
	timer_set_deferrable(timer);
}