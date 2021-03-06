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
typedef  int /*<<< orphan*/  u8 ;
struct nb8800_priv {scalar_t__ base; } ;

/* Variables and functions */
 int /*<<< orphan*/  readb_relaxed (scalar_t__) ; 

__attribute__((used)) static inline u8 nb8800_readb(struct nb8800_priv *priv, int reg)
{
	return readb_relaxed(priv->base + reg);
}