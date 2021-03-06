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
struct dbginterface {scalar_t__ fhndl; } ;

/* Variables and functions */
 int tcpip_write (scalar_t__,void const*,int) ; 

__attribute__((used)) static int writetcpip(struct dbginterface *device,const void *buffer,int size)
{
	if(device->fhndl>=0)
		return tcpip_write(device->fhndl,buffer,size);

	return 0;
}