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
typedef  int /*<<< orphan*/  encoder_t ;
typedef  int /*<<< orphan*/  block_t ;

/* Variables and functions */
 int /*<<< orphan*/  VLC_UNUSED (int /*<<< orphan*/ *) ; 

__attribute__((used)) static block_t *EncodeAudio( encoder_t *p_enc, block_t *p_buf )
{
    VLC_UNUSED(p_enc); VLC_UNUSED(p_buf);
    return NULL;
}