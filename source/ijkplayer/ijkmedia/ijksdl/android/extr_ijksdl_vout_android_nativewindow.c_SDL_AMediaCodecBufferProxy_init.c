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
typedef  int /*<<< orphan*/  SDL_AMediaCodecBufferProxy ;

/* Variables and functions */
 int /*<<< orphan*/  SDL_AMediaCodecBufferProxy_reset (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  assert (int /*<<< orphan*/ *) ; 

__attribute__((used)) static void SDL_AMediaCodecBufferProxy_init(SDL_AMediaCodecBufferProxy *proxy)
{
    assert(proxy);
    SDL_AMediaCodecBufferProxy_reset(proxy);
}