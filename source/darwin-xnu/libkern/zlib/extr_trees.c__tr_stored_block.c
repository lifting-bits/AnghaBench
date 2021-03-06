#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_5__   TYPE_1__ ;

/* Type definitions */
typedef  int ulg ;
struct TYPE_5__ {int compressed_len; } ;
typedef  TYPE_1__ deflate_state ;
typedef  int /*<<< orphan*/  charf ;

/* Variables and functions */
 int STORED_BLOCK ; 
 int /*<<< orphan*/  copy_block (TYPE_1__*,int /*<<< orphan*/ *,unsigned int,int) ; 
 int /*<<< orphan*/  send_bits (TYPE_1__*,int,int) ; 

void
_tr_stored_block(deflate_state *s, charf *buf, ulg stored_len, int eof)
{
    send_bits(s, (STORED_BLOCK<<1)+eof, 3);  /* send block type */
#ifdef DEBUG
    s->compressed_len = (s->compressed_len + 3 + 7) & (ulg)~7L;
    s->compressed_len += (stored_len + 4) << 3;
#endif
    copy_block(s, buf, (unsigned)stored_len, 1); /* with header */
}