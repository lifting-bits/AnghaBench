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
struct port {int dummy; } ;
struct bond_marker {int dummy; } ;

/* Variables and functions */

__attribute__((used)) static void ad_marker_response_received(struct bond_marker *marker,
	struct port *port)
{
	marker=NULL; // just to satisfy the compiler
	port=NULL;  // just to satisfy the compiler
	// DO NOTHING, SINCE WE DECIDED NOT TO IMPLEMENT THIS FEATURE FOR NOW
}