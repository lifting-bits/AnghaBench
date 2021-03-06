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
typedef  scalar_t__ u32 ;
struct echoaudio {int /*<<< orphan*/  asic_loaded; } ;

/* Variables and functions */
 scalar_t__ ASIC_ALREADY_LOADED ; 
 int /*<<< orphan*/  DE_ACT (char*) ; 
 int /*<<< orphan*/  DSP_VC_TEST_ASIC ; 
 int EIO ; 
 int /*<<< orphan*/  FALSE ; 
 int /*<<< orphan*/  TRUE ; 
 scalar_t__ read_dsp (struct echoaudio*,scalar_t__*) ; 
 int /*<<< orphan*/  send_vector (struct echoaudio*,int /*<<< orphan*/ ) ; 

__attribute__((used)) static int check_asic_status(struct echoaudio *chip)
{
	u32 asic_status;
	int goodcnt, i;

	chip->asic_loaded = FALSE;
	for (i = goodcnt = 0; i < 5; i++) {
		send_vector(chip, DSP_VC_TEST_ASIC);

		/* The DSP will return a value to indicate whether or not
		   the ASIC is currently loaded */
		if (read_dsp(chip, &asic_status) < 0) {
			DE_ACT(("check_asic_status: failed on read_dsp\n"));
			return -EIO;
		}

		if (asic_status == ASIC_ALREADY_LOADED) {
			if (++goodcnt == 3) {
				chip->asic_loaded = TRUE;
				return 0;
			}
		}
	}
	return -EIO;
}