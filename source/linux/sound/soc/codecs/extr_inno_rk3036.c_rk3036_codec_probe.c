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
struct snd_soc_component {int dummy; } ;

/* Variables and functions */
 int /*<<< orphan*/  rk3036_codec_reset (struct snd_soc_component*) ; 

__attribute__((used)) static int rk3036_codec_probe(struct snd_soc_component *component)
{
	rk3036_codec_reset(component);
	return 0;
}