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
typedef  int /*<<< orphan*/  u32 ;
struct ssb_gige {int dummy; } ;

/* Variables and functions */
 int /*<<< orphan*/  BUG_ON (int) ; 
 scalar_t__ SSB_GIGE_PCICFG ; 
 int /*<<< orphan*/  gige_write32 (struct ssb_gige*,scalar_t__,int /*<<< orphan*/ ) ; 

__attribute__((used)) static inline
void gige_pcicfg_write32(struct ssb_gige *dev,
			 unsigned int offset, u32 value)
{
	BUG_ON(offset >= 256);
	gige_write32(dev, SSB_GIGE_PCICFG + offset, value);
}