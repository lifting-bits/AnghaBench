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
struct bhnd_pcie2hb_softc {int dummy; } ;
typedef  int /*<<< orphan*/  device_t ;

/* Variables and functions */
 int /*<<< orphan*/  bhnd_pcie2_generic_detach (int /*<<< orphan*/ ) ; 
 int bhnd_pcie2_generic_resume (int /*<<< orphan*/ ) ; 
 int bhnd_pcie2_wars_hwup (struct bhnd_pcie2hb_softc*) ; 
 struct bhnd_pcie2hb_softc* device_get_softc (int /*<<< orphan*/ ) ; 

__attribute__((used)) static int
bhnd_pcie2_hostb_resume(device_t dev)
{
	struct bhnd_pcie2hb_softc	*sc;
	int				 error;

	sc = device_get_softc(dev);

	if ((error = bhnd_pcie2_generic_resume(dev)))
		return (error);

	/* Apply attach/resume work-arounds */
	if ((error = bhnd_pcie2_wars_hwup(sc))) {
		bhnd_pcie2_generic_detach(dev);
		return (error);
	}

	return (0);
}