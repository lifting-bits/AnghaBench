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
struct snd_uart16550 {int timer_running; int /*<<< orphan*/  buffer_timer; } ;

/* Variables and functions */
 int HZ ; 
 scalar_t__ jiffies ; 
 int /*<<< orphan*/  mod_timer (int /*<<< orphan*/ *,scalar_t__) ; 

__attribute__((used)) static inline void snd_uart16550_add_timer(struct snd_uart16550 *uart)
{
	if (!uart->timer_running) {
		/* timer 38600bps * 10bit * 16byte */
		mod_timer(&uart->buffer_timer, jiffies + (HZ + 255) / 256);
		uart->timer_running = 1;
	}
}