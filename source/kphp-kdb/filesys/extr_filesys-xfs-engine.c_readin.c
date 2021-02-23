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
 scalar_t__ BUFFSIZE ; 
 scalar_t__ Buff ; 
 int /*<<< orphan*/  assert (int) ; 
 int /*<<< orphan*/  idx_fd ; 
 int /*<<< orphan*/  kprintf (char*) ; 
 int /*<<< orphan*/  memcpy (scalar_t__,scalar_t__,scalar_t__) ; 
 int read (int /*<<< orphan*/ ,scalar_t__,scalar_t__) ; 
 scalar_t__ rptr ; 
 scalar_t__ wptr ; 

__attribute__((used)) static void *readin (size_t len) {
  assert (len >= 0);
  if (rptr + len <= wptr) {
    return rptr;
  }
  if (wptr < Buff + BUFFSIZE) {
    return 0;
  }
  memcpy (Buff, rptr, wptr - rptr);
  wptr -= rptr - Buff;
  rptr = Buff;
  int r = read (idx_fd, wptr, Buff + BUFFSIZE - wptr);
  if (r < 0) {
    kprintf ("error reading file: %m\n");
  } else {
    wptr += r;
  }
  if (rptr + len <= wptr) {
    return rptr;
  } else {
    return 0;
  }
}