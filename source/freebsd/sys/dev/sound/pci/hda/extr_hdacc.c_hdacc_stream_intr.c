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
struct hdacc_softc {int /*<<< orphan*/ *** streams; } ;
typedef  int /*<<< orphan*/ * device_t ;

/* Variables and functions */
 int /*<<< orphan*/  HDAC_STREAM_INTR (int /*<<< orphan*/ *,int,int) ; 
 struct hdacc_softc* device_get_softc (int /*<<< orphan*/ *) ; 

__attribute__((used)) static void
hdacc_stream_intr(device_t dev, int dir, int stream)
{
	struct hdacc_softc *codec = device_get_softc(dev);
	device_t child;

	if ((child = codec->streams[dir][stream]) != NULL)
		HDAC_STREAM_INTR(child, dir, stream);
}