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
typedef  int /*<<< orphan*/  TickType_t ;
typedef  int /*<<< orphan*/  Ringbuffer_t ;
typedef  scalar_t__ RingbufHandle_t ;

/* Variables and functions */
 int /*<<< orphan*/  configASSERT (int /*<<< orphan*/ *) ; 
 scalar_t__ pdTRUE ; 
 scalar_t__ prvReceiveGeneric (int /*<<< orphan*/ *,void**,int /*<<< orphan*/ *,size_t*,int /*<<< orphan*/ *,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 

void *xRingbufferReceive(RingbufHandle_t xRingbuffer, size_t *pxItemSize, TickType_t xTicksToWait)
{
    //Check arguments
    Ringbuffer_t *pxRingbuffer = (Ringbuffer_t *)xRingbuffer;
    configASSERT(pxRingbuffer);

    //Attempt to retrieve an item
    void *pvTempItem;
    size_t xTempSize;
    if (prvReceiveGeneric(pxRingbuffer, &pvTempItem, NULL, &xTempSize, NULL, 0, xTicksToWait) == pdTRUE) {
        if (pxItemSize != NULL) {
            *pxItemSize = xTempSize;
        }
        return pvTempItem;
    } else {
        return NULL;
    }
}