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
struct tty_struct {struct moxa_port* driver_data; } ;
struct moxa_port {int /*<<< orphan*/  statusflags; } ;

/* Variables and functions */
 int /*<<< orphan*/  LOWWAIT ; 
 int MoxaPortWriteData (struct tty_struct*,unsigned char const*,int) ; 
 int /*<<< orphan*/  moxa_lock ; 
 int /*<<< orphan*/  spin_lock_bh (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  spin_unlock_bh (int /*<<< orphan*/ *) ; 

__attribute__((used)) static int moxa_write(struct tty_struct *tty,
		      const unsigned char *buf, int count)
{
	struct moxa_port *ch = tty->driver_data;
	int len;

	if (ch == NULL)
		return 0;

	spin_lock_bh(&moxa_lock);
	len = MoxaPortWriteData(tty, buf, count);
	spin_unlock_bh(&moxa_lock);

	ch->statusflags |= LOWWAIT;
	return len;
}