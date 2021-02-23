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
typedef  int /*<<< orphan*/  HEVCContext ;

/* Variables and functions */
 size_t EXPLICIT_RDPCM_FLAG ; 
 int GET_CABAC (scalar_t__) ; 
 scalar_t__* elem_offset ; 

__attribute__((used)) static int explicit_rdpcm_flag_decode(HEVCContext *s, int c_idx)
{
    return GET_CABAC(elem_offset[EXPLICIT_RDPCM_FLAG] + !!c_idx);
}