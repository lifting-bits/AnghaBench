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

/* Variables and functions */
 int /*<<< orphan*/  printf (char*,int,int) ; 
 int /*<<< orphan*/  res ; 

void* runner(void* args)
{
  int cc;
  for ( cc = 0; cc < 10; cc ++ )
    {
    printf("%d CC: %d\n", (int)args, cc);
    }
  res ++;
  return 0;
}