#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_4__   TYPE_2__ ;
typedef  struct TYPE_3__   TYPE_1__ ;

/* Type definitions */
typedef  int /*<<< orphan*/  u64 ;
struct spu {int dummy; } ;
struct TYPE_4__ {TYPE_1__* shadow; } ;
struct TYPE_3__ {int /*<<< orphan*/  mfc_dar_RW; } ;

/* Variables and functions */
 int /*<<< orphan*/  in_be64 (int /*<<< orphan*/ *) ; 
 TYPE_2__* spu_pdata (struct spu*) ; 

__attribute__((used)) static u64 mfc_dar_get(struct spu *spu)
{
	return in_be64(&spu_pdata(spu)->shadow->mfc_dar_RW);
}