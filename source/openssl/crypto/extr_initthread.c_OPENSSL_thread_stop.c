#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_2__   TYPE_1__ ;

/* Type definitions */
struct TYPE_2__ {int sane; int /*<<< orphan*/  value; } ;
typedef  int /*<<< orphan*/  THREAD_EVENT_HANDLER ;

/* Variables and functions */
 int /*<<< orphan*/  OPENSSL_free (int /*<<< orphan*/ **) ; 
 TYPE_1__ destructor_key ; 
 int /*<<< orphan*/ ** init_get_thread_local (int /*<<< orphan*/ *,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  init_thread_remove_handlers (int /*<<< orphan*/ **) ; 
 int /*<<< orphan*/  init_thread_stop (int /*<<< orphan*/ *,int /*<<< orphan*/ **) ; 

void OPENSSL_thread_stop(void)
{
    if (destructor_key.sane != -1) {
        THREAD_EVENT_HANDLER **hands
            = init_get_thread_local(&destructor_key.value, 0, 0);
        init_thread_stop(NULL, hands);

        init_thread_remove_handlers(hands);
        OPENSSL_free(hands);
    }
}