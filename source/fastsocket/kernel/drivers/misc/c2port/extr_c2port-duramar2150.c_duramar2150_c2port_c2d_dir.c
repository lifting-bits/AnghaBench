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
typedef  int u8 ;
struct c2port_device {int dummy; } ;

/* Variables and functions */
 int C2D ; 
 int /*<<< orphan*/  DIR_PORT ; 
 int inb (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  mutex_lock (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  mutex_unlock (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  outb (int,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  update_lock ; 

__attribute__((used)) static void duramar2150_c2port_c2d_dir(struct c2port_device *dev, int dir)
{
	u8 v;

	mutex_lock(&update_lock);

	v = inb(DIR_PORT);

	if (dir)
		outb(v & ~C2D, DIR_PORT);
	else
		outb(v | C2D, DIR_PORT);

	mutex_unlock(&update_lock);
}