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

/* Variables and functions */
 int /*<<< orphan*/  emit_adc (int,int) ; 
 int /*<<< orphan*/  emit_cmpimm (int,int) ; 
 int /*<<< orphan*/  emit_shrimm (int,int,int) ; 

void emit_cmppz(int s, int sr)
{
  emit_shrimm(sr,1,sr);
  emit_cmpimm(s,0x80000000);
  emit_adc(sr,sr);
}