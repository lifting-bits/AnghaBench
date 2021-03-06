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
struct nand_sdr_timings {int dummy; } ;
struct nand_data_interface {int dummy; } ;
struct nand_chip {int dummy; } ;

/* Variables and functions */
 scalar_t__ IS_ERR (struct nand_sdr_timings const*) ; 
 int NAND_DATA_IFACE_CHECK_ONLY ; 
 int PTR_ERR (struct nand_sdr_timings const*) ; 
 struct nand_sdr_timings* nand_get_sdr_timings (struct nand_data_interface const*) ; 
 int /*<<< orphan*/  stm32_fmc2_calc_timings (struct nand_chip*,struct nand_sdr_timings const*) ; 
 int /*<<< orphan*/  stm32_fmc2_timings_init (struct nand_chip*) ; 

__attribute__((used)) static int stm32_fmc2_setup_interface(struct nand_chip *chip, int chipnr,
				      const struct nand_data_interface *conf)
{
	const struct nand_sdr_timings *sdrt;

	sdrt = nand_get_sdr_timings(conf);
	if (IS_ERR(sdrt))
		return PTR_ERR(sdrt);

	if (chipnr == NAND_DATA_IFACE_CHECK_ONLY)
		return 0;

	stm32_fmc2_calc_timings(chip, sdrt);

	/* Apply timings */
	stm32_fmc2_timings_init(chip);

	return 0;
}