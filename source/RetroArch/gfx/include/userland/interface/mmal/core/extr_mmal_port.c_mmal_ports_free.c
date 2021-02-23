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
typedef  int /*<<< orphan*/  MMAL_PORT_T ;

/* Variables and functions */
 int /*<<< orphan*/  mmal_port_free (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  vcos_free (int /*<<< orphan*/ **) ; 

void mmal_ports_free(MMAL_PORT_T **ports, unsigned int ports_num)
{
   unsigned int i;

   for (i = 0; i < ports_num; i++)
      mmal_port_free(ports[i]);
   vcos_free(ports);
}