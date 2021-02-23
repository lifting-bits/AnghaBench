#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_5__   TYPE_1__ ;

/* Type definitions */
struct TYPE_5__ {struct TYPE_5__* data; } ;
typedef  TYPE_1__ MyList ;

/* Variables and functions */
 int /*<<< orphan*/  free (TYPE_1__*) ; 
 int /*<<< orphan*/  mylist_resize (TYPE_1__*,int /*<<< orphan*/ ,int) ; 

void mylist_destroy(MyList **list_p)
{
   MyList *list = NULL;
   if (!list_p)
      return;

   list = *list_p;

   if (list)
   {
      mylist_resize(list, 0, false);
      free(list->data);
      free(list);
      *list_p = NULL;
   }
}