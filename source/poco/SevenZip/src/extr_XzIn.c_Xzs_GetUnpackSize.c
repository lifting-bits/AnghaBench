#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_3__   TYPE_1__ ;

/* Type definitions */
typedef  int /*<<< orphan*/  UInt64 ;
struct TYPE_3__ {size_t num; int /*<<< orphan*/ * streams; } ;
typedef  TYPE_1__ CXzs ;

/* Variables and functions */
 int /*<<< orphan*/  ADD_SIZE_CHECH (int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  Xz_GetUnpackSize (int /*<<< orphan*/ *) ; 

UInt64 Xzs_GetUnpackSize(const CXzs *p)
{
  UInt64 size = 0;
  size_t i;
  for (i = 0; i < p->num; i++)
    ADD_SIZE_CHECH(size, Xz_GetUnpackSize(&p->streams[i]));
  return size;
}