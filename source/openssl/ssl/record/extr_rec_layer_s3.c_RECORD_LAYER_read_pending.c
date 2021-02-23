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
struct TYPE_3__ {int /*<<< orphan*/  rbuf; } ;
typedef  TYPE_1__ RECORD_LAYER ;

/* Variables and functions */
 scalar_t__ SSL3_BUFFER_get_left (int /*<<< orphan*/ *) ; 

int RECORD_LAYER_read_pending(const RECORD_LAYER *rl)
{
    return SSL3_BUFFER_get_left(&rl->rbuf) != 0;
}