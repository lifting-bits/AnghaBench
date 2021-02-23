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
typedef  int /*<<< orphan*/  u_int ;
struct acpi_device {int /*<<< orphan*/  ad_rl; } ;
typedef  int /*<<< orphan*/ * device_t ;

/* Variables and functions */
 int /*<<< orphan*/  M_ACPIDEV ; 
 int M_NOWAIT ; 
 int M_ZERO ; 
 int /*<<< orphan*/ * device_add_child_ordered (int /*<<< orphan*/ *,int /*<<< orphan*/ ,char const*,int) ; 
 int /*<<< orphan*/  device_set_ivars (int /*<<< orphan*/ *,struct acpi_device*) ; 
 int /*<<< orphan*/  free (struct acpi_device*,int /*<<< orphan*/ ) ; 
 struct acpi_device* malloc (int,int /*<<< orphan*/ ,int) ; 
 int /*<<< orphan*/  resource_list_init (int /*<<< orphan*/ *) ; 

__attribute__((used)) static device_t
acpi_add_child(device_t bus, u_int order, const char *name, int unit)
{
    struct acpi_device	*ad;
    device_t		child;

    if ((ad = malloc(sizeof(*ad), M_ACPIDEV, M_NOWAIT | M_ZERO)) == NULL)
	return (NULL);

    resource_list_init(&ad->ad_rl);

    child = device_add_child_ordered(bus, order, name, unit);
    if (child != NULL)
	device_set_ivars(child, ad);
    else
	free(ad, M_ACPIDEV);
    return (child);
}