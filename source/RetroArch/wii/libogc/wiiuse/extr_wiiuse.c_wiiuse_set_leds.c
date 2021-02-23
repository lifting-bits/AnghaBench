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
typedef  int ubyte ;
struct wiimote_t {int leds; } ;
typedef  int /*<<< orphan*/  cmd_blk_cb ;

/* Variables and functions */
 int /*<<< orphan*/  WIIMOTE_IS_CONNECTED (struct wiimote_t*) ; 
 int /*<<< orphan*/  WM_CMD_LED ; 
 int /*<<< orphan*/  wiiuse_sendcmd (struct wiimote_t*,int /*<<< orphan*/ ,int*,int,int /*<<< orphan*/ ) ; 

void wiiuse_set_leds(struct wiimote_t *wm,int leds,cmd_blk_cb cb)
{
	ubyte buf;

	if(!wm || !WIIMOTE_IS_CONNECTED(wm)) return;

	wm->leds = (leds&0xf0);

	buf = wm->leds;
	wiiuse_sendcmd(wm,WM_CMD_LED,&buf,1,cb);
}