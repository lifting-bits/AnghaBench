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
struct au1xpsc_audio_data {scalar_t__ mmio; } ;

/* Variables and functions */
 unsigned long __raw_readl (scalar_t__) ; 

__attribute__((used)) static inline unsigned long RD(struct au1xpsc_audio_data *ctx, int reg)
{
	return __raw_readl(ctx->mmio + reg);
}