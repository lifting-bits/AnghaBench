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
struct sbus_icarg {int /*<<< orphan*/  sica_clr; int /*<<< orphan*/  sica_sc; } ;
struct intr_vector {struct sbus_icarg* iv_icarg; } ;

/* Variables and functions */
 int /*<<< orphan*/  INTCLR_IDLE ; 
 int /*<<< orphan*/  SYSIO_WRITE8 (int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 

__attribute__((used)) static void
sbus_intr_clear(void *arg)
{
	struct intr_vector *iv = arg;
	struct sbus_icarg *sica = iv->iv_icarg;

	SYSIO_WRITE8(sica->sica_sc, sica->sica_clr, INTCLR_IDLE);
}