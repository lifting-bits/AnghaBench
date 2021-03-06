#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_7__   TYPE_3__ ;
typedef  struct TYPE_6__   TYPE_2__ ;
typedef  struct TYPE_5__   TYPE_1__ ;

/* Type definitions */
struct TYPE_5__ {int tag; } ;
struct TYPE_6__ {TYPE_1__ s; } ;
struct TYPE_7__ {scalar_t__ type; TYPE_2__ u; } ;
typedef  TYPE_3__ jsval_t ;
typedef  int BOOL ;

/* Variables and functions */
 scalar_t__ JSV_NUMBER ; 

__attribute__((used)) static inline BOOL is_number(jsval_t v)
{
#ifdef JSVAL_DOUBLE_LAYOUT_PTR32
    return (v.u.s.tag & 0x7ff80000) != 0x7ff80000;
#else
    return v.type == JSV_NUMBER;
#endif
}