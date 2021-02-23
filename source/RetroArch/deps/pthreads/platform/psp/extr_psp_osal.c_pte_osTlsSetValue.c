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
typedef  int /*<<< orphan*/  pte_osResult ;

/* Variables and functions */
 void* getTlsStructFromThread (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  pteTlsSetValue (void*,unsigned int,void*) ; 
 int /*<<< orphan*/  sceKernelGetThreadId () ; 

pte_osResult pte_osTlsSetValue(unsigned int key, void * value)
{
   void *pTls = getTlsStructFromThread(sceKernelGetThreadId());

   return pteTlsSetValue(pTls, key, value);
}