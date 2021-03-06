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
typedef  int uint32_t ;
typedef  enum a2xx_pa_su_sc_polymode { ____Placeholder_a2xx_pa_su_sc_polymode } a2xx_pa_su_sc_polymode ;

/* Variables and functions */
 int A2XX_PA_SU_SC_MODE_CNTL_POLYMODE__MASK ; 
 int A2XX_PA_SU_SC_MODE_CNTL_POLYMODE__SHIFT ; 

__attribute__((used)) static inline uint32_t A2XX_PA_SU_SC_MODE_CNTL_POLYMODE(enum a2xx_pa_su_sc_polymode val)
{
	return ((val) << A2XX_PA_SU_SC_MODE_CNTL_POLYMODE__SHIFT) & A2XX_PA_SU_SC_MODE_CNTL_POLYMODE__MASK;
}