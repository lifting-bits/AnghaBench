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
typedef  int SYS_MODULE_OBJ ;

/* Variables and functions */
 int /*<<< orphan*/  DRV_SPI0_Tasks () ; 
#define  DRV_SPI_INDEX_0 128 

void DRV_SPI_Tasks ( SYS_MODULE_OBJ object )
{
    switch(object)
    {
        case DRV_SPI_INDEX_0:
        {
            DRV_SPI0_Tasks();
            break;
        }
        default:
        {
            break;
        }
    }
}