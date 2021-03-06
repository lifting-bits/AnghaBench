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
struct aic23 {int /*<<< orphan*/  regmap; } ;

/* Variables and functions */
 int /*<<< orphan*/  regcache_mark_dirty (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  regcache_sync (int /*<<< orphan*/ ) ; 
 struct aic23* snd_soc_component_get_drvdata (struct snd_soc_component*) ; 

__attribute__((used)) static int tlv320aic23_resume(struct snd_soc_component *component)
{
	struct aic23 *aic23 = snd_soc_component_get_drvdata(component);
	regcache_mark_dirty(aic23->regmap);
	regcache_sync(aic23->regmap);

	return 0;
}