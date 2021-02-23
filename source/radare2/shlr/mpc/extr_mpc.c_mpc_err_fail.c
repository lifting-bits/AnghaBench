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
struct TYPE_6__ {char const* filename; int /*<<< orphan*/  state; scalar_t__ suppress; } ;
typedef  TYPE_1__ mpc_input_t ;
struct TYPE_7__ {char recieved; void* failure; int /*<<< orphan*/ * expected; scalar_t__ expected_num; int /*<<< orphan*/  state; void* filename; } ;
typedef  TYPE_2__ mpc_err_t ;

/* Variables and functions */
 void* mpc_malloc (TYPE_1__*,int) ; 
 int /*<<< orphan*/  strcpy (void*,char const*) ; 
 int strlen (char const*) ; 

__attribute__((used)) static mpc_err_t *mpc_err_fail(mpc_input_t *i, const char *failure) {
  mpc_err_t *x;
  if (i->suppress) { return NULL; }
  x = mpc_malloc(i, sizeof(mpc_err_t));
  x->filename = mpc_malloc(i, strlen(i->filename) + 1);
  strcpy(x->filename, i->filename);
  x->state = i->state;
  x->expected_num = 0;
  x->expected = NULL;
  x->failure = mpc_malloc(i, strlen(failure) + 1);
  strcpy(x->failure, failure);
  x->recieved = ' ';
  return x;
}