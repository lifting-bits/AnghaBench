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
struct _cms_typehandler_struct {int dummy; } ;
typedef  int cmsUInt32Number ;
typedef  int /*<<< orphan*/  cmsContext ;

/* Variables and functions */
 void* _cmsDupMem (int /*<<< orphan*/ ,void const*,int) ; 

__attribute__((used)) static
void* Type_int_Dup(cmsContext ContextID, struct _cms_typehandler_struct* self,
                   const void *Ptr, cmsUInt32Number n)
{
    return _cmsDupMem(ContextID, Ptr, n * sizeof(cmsUInt32Number));
}