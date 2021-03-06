#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_3__   TYPE_1__ ;

/* Type definitions */
struct TYPE_3__ {int len; char* data; } ;
typedef  TYPE_1__ barray ;

/* Variables and functions */
 scalar_t__ ISPRINT (char) ; 
 int /*<<< orphan*/  printf (char*,...) ; 

__attribute__((used)) static void
pbarray (barray *y)
{
  int x;

  printf ("%d (", y->len);

  for (x = 0; x < y->len; x++)
    printf ("(%02x %c)", y->data[x],
	    ISPRINT (y->data[x]) ? y->data[x] : '.');

  printf (")\n");
}