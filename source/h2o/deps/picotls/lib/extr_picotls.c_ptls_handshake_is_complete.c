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
struct TYPE_3__ {scalar_t__ state; } ;
typedef  TYPE_1__ ptls_t ;

/* Variables and functions */
 scalar_t__ PTLS_STATE_POST_HANDSHAKE_MIN ; 

int ptls_handshake_is_complete(ptls_t *tls)
{
    return tls->state >= PTLS_STATE_POST_HANDSHAKE_MIN;
}