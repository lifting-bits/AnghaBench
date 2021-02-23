#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_6__   TYPE_1__ ;

/* Type definitions */
struct TYPE_6__ {scalar_t__ len; scalar_t__ str; } ;
typedef  TYPE_1__ AVBPrint ;

/* Variables and functions */
 unsigned int FFMIN (unsigned int,unsigned int) ; 
 scalar_t__ av_bprint_alloc (TYPE_1__*,unsigned int) ; 
 int /*<<< orphan*/  av_bprint_grow (TYPE_1__*,unsigned int) ; 
 unsigned int av_bprint_room (TYPE_1__*) ; 
 int /*<<< orphan*/  memcpy (scalar_t__,char const*,unsigned int) ; 

void av_bprint_append_data(AVBPrint *buf, const char *data, unsigned size)
{
    unsigned room, real_n;

    while (1) {
        room = av_bprint_room(buf);
        if (size < room)
            break;
        if (av_bprint_alloc(buf, size))
            break;
    }
    if (room) {
        real_n = FFMIN(size, room - 1);
        memcpy(buf->str + buf->len, data, real_n);
    }
    av_bprint_grow(buf, size);
}