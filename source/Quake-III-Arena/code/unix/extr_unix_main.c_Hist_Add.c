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
typedef  int /*<<< orphan*/  field_t ;

/* Variables and functions */
 int TTY_HISTORY ; 
 int /*<<< orphan*/  assert (int) ; 
 int hist_count ; 
 int hist_current ; 
 int /*<<< orphan*/ * ttyEditLines ; 

void Hist_Add(field_t *field)
{
  int i;
  assert(hist_count <= TTY_HISTORY);
  assert(hist_count >= 0);
  assert(hist_current >= -1);
  assert(hist_current <= hist_count);
  // make some room
  for (i=TTY_HISTORY-1; i>0; i--)
  {
    ttyEditLines[i] = ttyEditLines[i-1];
  }
  ttyEditLines[0] = *field;
  if (hist_count<TTY_HISTORY)
  {
    hist_count++;
  }
  hist_current = -1; // re-init
}