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
struct fotg210_hcd {int dummy; } ;
typedef  int /*<<< orphan*/  __hc32 ;

/* Variables and functions */
 int /*<<< orphan*/  le32_to_cpu (int /*<<< orphan*/  const) ; 

__attribute__((used)) static inline u32 hc32_to_cpu(const struct fotg210_hcd *fotg210, const __hc32 x)
{
	return le32_to_cpu(x);
}