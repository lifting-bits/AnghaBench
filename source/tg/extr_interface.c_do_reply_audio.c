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
struct in_ev {int dummy; } ;
struct command {int dummy; } ;
struct arg {int dummy; } ;

/* Variables and functions */
 int /*<<< orphan*/  TGL_SEND_MSG_FLAG_DOCUMENT_AUDIO ; 
 int /*<<< orphan*/  _do_reply_file (struct command*,int,struct arg*,struct in_ev*,int /*<<< orphan*/ ) ; 

void do_reply_audio (struct command *command, int arg_num, struct arg args[], struct in_ev *ev) {
  _do_reply_file (command, arg_num, args, ev, TGL_SEND_MSG_FLAG_DOCUMENT_AUDIO);
}