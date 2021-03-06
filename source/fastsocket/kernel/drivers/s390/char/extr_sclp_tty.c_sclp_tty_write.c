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
struct tty_struct {int dummy; } ;

/* Variables and functions */
 unsigned char const* sclp_tty_chars ; 
 scalar_t__ sclp_tty_chars_count ; 
 int sclp_tty_write_string (unsigned char const*,int,int) ; 

__attribute__((used)) static int
sclp_tty_write(struct tty_struct *tty, const unsigned char *buf, int count)
{
	if (sclp_tty_chars_count > 0) {
		sclp_tty_write_string(sclp_tty_chars, sclp_tty_chars_count, 0);
		sclp_tty_chars_count = 0;
	}
	return sclp_tty_write_string(buf, count, 1);
}