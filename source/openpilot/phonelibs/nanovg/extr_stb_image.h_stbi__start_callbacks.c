#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_4__   TYPE_1__ ;

/* Type definitions */
typedef  int /*<<< orphan*/  stbi_io_callbacks ;
struct TYPE_4__ {int buflen; int read_from_callbacks; int /*<<< orphan*/  img_buffer_end; int /*<<< orphan*/  img_buffer_original_end; int /*<<< orphan*/  buffer_start; int /*<<< orphan*/  img_buffer_original; void* io_user_data; int /*<<< orphan*/  io; } ;
typedef  TYPE_1__ stbi__context ;

/* Variables and functions */
 int /*<<< orphan*/  stbi__refill_buffer (TYPE_1__*) ; 

__attribute__((used)) static void stbi__start_callbacks(stbi__context *s, stbi_io_callbacks *c, void *user)
{
   s->io = *c;
   s->io_user_data = user;
   s->buflen = sizeof(s->buffer_start);
   s->read_from_callbacks = 1;
   s->img_buffer_original = s->buffer_start;
   stbi__refill_buffer(s);
   s->img_buffer_original_end = s->img_buffer_end;
}