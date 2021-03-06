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
struct kill {int how_often_length; int /*<<< orphan*/ * how_often_data; int /*<<< orphan*/  how_often_set; } ;
typedef  int /*<<< orphan*/  ev_uint32_t ;

/* Variables and functions */

int
kill_how_often_assign(struct kill *msg, int off,
    const ev_uint32_t value)
{
  if (!msg->how_often_set || off < 0 || off >= msg->how_often_length)
    return (-1);

  {
    msg->how_often_data[off] = value;
  }
  return (0);
}