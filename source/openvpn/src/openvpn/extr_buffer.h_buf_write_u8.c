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
typedef  int /*<<< orphan*/  uint8_t ;
struct buffer {int dummy; } ;

/* Variables and functions */
 int buf_write (struct buffer*,int /*<<< orphan*/ *,int) ; 

__attribute__((used)) static inline bool
buf_write_u8(struct buffer *dest, int data)
{
    uint8_t u8 = (uint8_t) data;
    return buf_write(dest, &u8, sizeof(uint8_t));
}