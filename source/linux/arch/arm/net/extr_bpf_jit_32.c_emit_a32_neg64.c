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
struct jit_ctx {int dummy; } ;
typedef  int /*<<< orphan*/  s8 ;

/* Variables and functions */
 int /*<<< orphan*/  ARM_RSBS_I (int /*<<< orphan*/  const,int /*<<< orphan*/  const,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  ARM_RSC_I (int /*<<< orphan*/  const,int /*<<< orphan*/  const,int /*<<< orphan*/ ) ; 
 size_t TMP_REG_1 ; 
 int /*<<< orphan*/ * arm_bpf_get_reg64 (int /*<<< orphan*/  const*,int /*<<< orphan*/  const*,struct jit_ctx*) ; 
 int /*<<< orphan*/  arm_bpf_put_reg64 (int /*<<< orphan*/  const*,int /*<<< orphan*/  const*,struct jit_ctx*) ; 
 int /*<<< orphan*/ ** bpf2a32 ; 
 int /*<<< orphan*/  emit (int /*<<< orphan*/ ,struct jit_ctx*) ; 

__attribute__((used)) static inline void emit_a32_neg64(const s8 dst[],
				struct jit_ctx *ctx){
	const s8 *tmp = bpf2a32[TMP_REG_1];
	const s8 *rd;

	/* Setup Operand */
	rd = arm_bpf_get_reg64(dst, tmp, ctx);

	/* Do Negate Operation */
	emit(ARM_RSBS_I(rd[1], rd[1], 0), ctx);
	emit(ARM_RSC_I(rd[0], rd[0], 0), ctx);

	arm_bpf_put_reg64(dst, rd, ctx);
}