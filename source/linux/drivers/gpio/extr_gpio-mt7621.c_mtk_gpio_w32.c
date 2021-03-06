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
typedef  scalar_t__ u32 ;
struct gpio_chip {int /*<<< orphan*/  (* write_reg ) (scalar_t__,scalar_t__) ;} ;
struct mtk_gc {int bank; struct gpio_chip chip; } ;
struct mtk {scalar_t__ base; } ;

/* Variables and functions */
 int GPIO_BANK_STRIDE ; 
 struct mtk* gpiochip_get_data (struct gpio_chip*) ; 
 int /*<<< orphan*/  stub1 (scalar_t__,scalar_t__) ; 

__attribute__((used)) static inline void
mtk_gpio_w32(struct mtk_gc *rg, u32 offset, u32 val)
{
	struct gpio_chip *gc = &rg->chip;
	struct mtk *mtk = gpiochip_get_data(gc);

	offset = (rg->bank * GPIO_BANK_STRIDE) + offset;
	gc->write_reg(mtk->base + offset, val);
}