#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_3__   TYPE_1__ ;

/* Type definitions */
typedef  int u32 ;
typedef  size_t s32 ;
typedef  int /*<<< orphan*/  cardcallback ;
struct TYPE_3__ {int cmd_sector_addr; int cmd_blck_cnt; int /*<<< orphan*/  card_xfer_cb; void* cmd_usr_buf; } ;
typedef  TYPE_1__ card_block ;

/* Variables and functions */
 size_t CARD_ERROR_NOCARD ; 
 size_t EXI_CHANNEL_0 ; 
 size_t EXI_CHANNEL_2 ; 
 int /*<<< orphan*/  __blockreadcallback ; 
 size_t __card_readsegment (size_t,int /*<<< orphan*/ ) ; 
 TYPE_1__* cardmap ; 

__attribute__((used)) static s32 __card_read(s32 chn,u32 address,u32 block_len,void *buffer,cardcallback callback)
{
	s32 ret;
	card_block *card = NULL;
	if(chn<EXI_CHANNEL_0 || chn>=EXI_CHANNEL_2) return CARD_ERROR_NOCARD;
	card = &cardmap[chn];

	card->cmd_sector_addr = address;
	card->cmd_blck_cnt = block_len>>9;
	card->cmd_usr_buf = buffer;
	card->card_xfer_cb = callback;
	ret = __card_readsegment(chn,__blockreadcallback);

	return ret;
}