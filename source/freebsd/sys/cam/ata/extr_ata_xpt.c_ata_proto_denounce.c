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
struct cam_ed {int /*<<< orphan*/  ident_data; } ;

/* Variables and functions */
 int /*<<< orphan*/  ata_print_ident_short (int /*<<< orphan*/ *) ; 

__attribute__((used)) static void
ata_proto_denounce(struct cam_ed *device)
{
	ata_print_ident_short(&device->ident_data);
}