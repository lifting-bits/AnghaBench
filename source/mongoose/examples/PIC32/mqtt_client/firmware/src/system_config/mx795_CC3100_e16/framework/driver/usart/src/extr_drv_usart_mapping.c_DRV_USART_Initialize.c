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
typedef  int /*<<< orphan*/  SYS_MODULE_OBJ ;
typedef  int /*<<< orphan*/  SYS_MODULE_INIT ;
typedef  int SYS_MODULE_INDEX ;

/* Variables and functions */
 int /*<<< orphan*/  DRV_USART0_Initialize () ; 
#define  DRV_USART_INDEX_0 128 
 int /*<<< orphan*/  SYS_MODULE_OBJ_INVALID ; 

SYS_MODULE_OBJ DRV_USART_Initialize(const SYS_MODULE_INDEX index,const SYS_MODULE_INIT * const init)
{
    SYS_MODULE_OBJ returnValue;

    switch(index)
    {
        case DRV_USART_INDEX_0:
        {
            returnValue = DRV_USART0_Initialize();
            break;
        }
        default:
        {
            returnValue = SYS_MODULE_OBJ_INVALID;
            break;
        }
    }
    return returnValue;
}