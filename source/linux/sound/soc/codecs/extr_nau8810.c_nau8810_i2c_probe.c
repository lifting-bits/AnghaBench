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
struct nau8810 {int /*<<< orphan*/  regmap; struct device* dev; } ;
struct i2c_device_id {int dummy; } ;
struct device {int dummy; } ;
struct i2c_client {struct device dev; } ;

/* Variables and functions */
 int ENOMEM ; 
 int /*<<< orphan*/  GFP_KERNEL ; 
 scalar_t__ IS_ERR (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  NAU8810_REG_RESET ; 
 int PTR_ERR (int /*<<< orphan*/ ) ; 
 struct nau8810* dev_get_platdata (struct device*) ; 
 struct nau8810* devm_kzalloc (struct device*,int,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  devm_regmap_init_i2c (struct i2c_client*,int /*<<< orphan*/ *) ; 
 int devm_snd_soc_register_component (struct device*,int /*<<< orphan*/ *,int /*<<< orphan*/ *,int) ; 
 int /*<<< orphan*/  i2c_set_clientdata (struct i2c_client*,struct nau8810*) ; 
 int /*<<< orphan*/  nau8810_component_driver ; 
 int /*<<< orphan*/  nau8810_dai ; 
 int /*<<< orphan*/  nau8810_regmap_config ; 
 int /*<<< orphan*/  regmap_write (int /*<<< orphan*/ ,int /*<<< orphan*/ ,int) ; 

__attribute__((used)) static int nau8810_i2c_probe(struct i2c_client *i2c,
			    const struct i2c_device_id *id)
{
	struct device *dev = &i2c->dev;
	struct nau8810 *nau8810 = dev_get_platdata(dev);

	if (!nau8810) {
		nau8810 = devm_kzalloc(dev, sizeof(*nau8810), GFP_KERNEL);
		if (!nau8810)
			return -ENOMEM;
	}
	i2c_set_clientdata(i2c, nau8810);

	nau8810->regmap = devm_regmap_init_i2c(i2c, &nau8810_regmap_config);
	if (IS_ERR(nau8810->regmap))
		return PTR_ERR(nau8810->regmap);
	nau8810->dev = dev;

	regmap_write(nau8810->regmap, NAU8810_REG_RESET, 0x00);

	return devm_snd_soc_register_component(dev,
		&nau8810_component_driver, &nau8810_dai, 1);
}