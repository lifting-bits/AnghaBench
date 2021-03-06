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
typedef  int /*<<< orphan*/  u16 ;
struct pci_dev {int device; } ;

/* Variables and functions */
#define  MPI25_MFGPAGE_DEVID_SAS3004 174 
#define  MPI25_MFGPAGE_DEVID_SAS3008 173 
#define  MPI25_MFGPAGE_DEVID_SAS3108_1 172 
#define  MPI25_MFGPAGE_DEVID_SAS3108_2 171 
#define  MPI25_MFGPAGE_DEVID_SAS3108_5 170 
#define  MPI25_MFGPAGE_DEVID_SAS3108_6 169 
 int /*<<< orphan*/  MPI25_VERSION ; 
#define  MPI26_ATLAS_PCIe_SWITCH_DEVID 168 
#define  MPI26_MFGPAGE_DEVID_CFG_SEC_3816 167 
#define  MPI26_MFGPAGE_DEVID_CFG_SEC_3916 166 
#define  MPI26_MFGPAGE_DEVID_HARD_SEC_3816 165 
#define  MPI26_MFGPAGE_DEVID_HARD_SEC_3916 164 
#define  MPI26_MFGPAGE_DEVID_SAS3216 163 
#define  MPI26_MFGPAGE_DEVID_SAS3224 162 
#define  MPI26_MFGPAGE_DEVID_SAS3316_1 161 
#define  MPI26_MFGPAGE_DEVID_SAS3316_2 160 
#define  MPI26_MFGPAGE_DEVID_SAS3316_3 159 
#define  MPI26_MFGPAGE_DEVID_SAS3316_4 158 
#define  MPI26_MFGPAGE_DEVID_SAS3324_1 157 
#define  MPI26_MFGPAGE_DEVID_SAS3324_2 156 
#define  MPI26_MFGPAGE_DEVID_SAS3324_3 155 
#define  MPI26_MFGPAGE_DEVID_SAS3324_4 154 
#define  MPI26_MFGPAGE_DEVID_SAS3408 153 
#define  MPI26_MFGPAGE_DEVID_SAS3416 152 
#define  MPI26_MFGPAGE_DEVID_SAS3508 151 
#define  MPI26_MFGPAGE_DEVID_SAS3508_1 150 
#define  MPI26_MFGPAGE_DEVID_SAS3516 149 
#define  MPI26_MFGPAGE_DEVID_SAS3516_1 148 
#define  MPI26_MFGPAGE_DEVID_SAS3616 147 
 int /*<<< orphan*/  MPI26_VERSION ; 
#define  MPI2_MFGPAGE_DEVID_SAS2004 146 
#define  MPI2_MFGPAGE_DEVID_SAS2008 145 
#define  MPI2_MFGPAGE_DEVID_SAS2108_1 144 
#define  MPI2_MFGPAGE_DEVID_SAS2108_2 143 
#define  MPI2_MFGPAGE_DEVID_SAS2108_3 142 
#define  MPI2_MFGPAGE_DEVID_SAS2116_1 141 
#define  MPI2_MFGPAGE_DEVID_SAS2116_2 140 
#define  MPI2_MFGPAGE_DEVID_SAS2208_1 139 
#define  MPI2_MFGPAGE_DEVID_SAS2208_2 138 
#define  MPI2_MFGPAGE_DEVID_SAS2208_3 137 
#define  MPI2_MFGPAGE_DEVID_SAS2208_4 136 
#define  MPI2_MFGPAGE_DEVID_SAS2208_5 135 
#define  MPI2_MFGPAGE_DEVID_SAS2208_6 134 
#define  MPI2_MFGPAGE_DEVID_SAS2308_1 133 
#define  MPI2_MFGPAGE_DEVID_SAS2308_2 132 
#define  MPI2_MFGPAGE_DEVID_SAS2308_3 131 
#define  MPI2_MFGPAGE_DEVID_SSS6200 130 
#define  MPI2_MFGPAGE_DEVID_SWITCH_MPI_EP 129 
#define  MPI2_MFGPAGE_DEVID_SWITCH_MPI_EP_1 128 
 int /*<<< orphan*/  MPI2_VERSION ; 

__attribute__((used)) static u16
_scsih_determine_hba_mpi_version(struct pci_dev *pdev)
{

	switch (pdev->device) {
	case MPI2_MFGPAGE_DEVID_SSS6200:
	case MPI2_MFGPAGE_DEVID_SAS2004:
	case MPI2_MFGPAGE_DEVID_SAS2008:
	case MPI2_MFGPAGE_DEVID_SAS2108_1:
	case MPI2_MFGPAGE_DEVID_SAS2108_2:
	case MPI2_MFGPAGE_DEVID_SAS2108_3:
	case MPI2_MFGPAGE_DEVID_SAS2116_1:
	case MPI2_MFGPAGE_DEVID_SAS2116_2:
	case MPI2_MFGPAGE_DEVID_SAS2208_1:
	case MPI2_MFGPAGE_DEVID_SAS2208_2:
	case MPI2_MFGPAGE_DEVID_SAS2208_3:
	case MPI2_MFGPAGE_DEVID_SAS2208_4:
	case MPI2_MFGPAGE_DEVID_SAS2208_5:
	case MPI2_MFGPAGE_DEVID_SAS2208_6:
	case MPI2_MFGPAGE_DEVID_SAS2308_1:
	case MPI2_MFGPAGE_DEVID_SAS2308_2:
	case MPI2_MFGPAGE_DEVID_SAS2308_3:
	case MPI2_MFGPAGE_DEVID_SWITCH_MPI_EP:
	case MPI2_MFGPAGE_DEVID_SWITCH_MPI_EP_1:
		return MPI2_VERSION;
	case MPI25_MFGPAGE_DEVID_SAS3004:
	case MPI25_MFGPAGE_DEVID_SAS3008:
	case MPI25_MFGPAGE_DEVID_SAS3108_1:
	case MPI25_MFGPAGE_DEVID_SAS3108_2:
	case MPI25_MFGPAGE_DEVID_SAS3108_5:
	case MPI25_MFGPAGE_DEVID_SAS3108_6:
		return MPI25_VERSION;
	case MPI26_MFGPAGE_DEVID_SAS3216:
	case MPI26_MFGPAGE_DEVID_SAS3224:
	case MPI26_MFGPAGE_DEVID_SAS3316_1:
	case MPI26_MFGPAGE_DEVID_SAS3316_2:
	case MPI26_MFGPAGE_DEVID_SAS3316_3:
	case MPI26_MFGPAGE_DEVID_SAS3316_4:
	case MPI26_MFGPAGE_DEVID_SAS3324_1:
	case MPI26_MFGPAGE_DEVID_SAS3324_2:
	case MPI26_MFGPAGE_DEVID_SAS3324_3:
	case MPI26_MFGPAGE_DEVID_SAS3324_4:
	case MPI26_MFGPAGE_DEVID_SAS3508:
	case MPI26_MFGPAGE_DEVID_SAS3508_1:
	case MPI26_MFGPAGE_DEVID_SAS3408:
	case MPI26_MFGPAGE_DEVID_SAS3516:
	case MPI26_MFGPAGE_DEVID_SAS3516_1:
	case MPI26_MFGPAGE_DEVID_SAS3416:
	case MPI26_MFGPAGE_DEVID_SAS3616:
	case MPI26_ATLAS_PCIe_SWITCH_DEVID:
	case MPI26_MFGPAGE_DEVID_CFG_SEC_3916:
	case MPI26_MFGPAGE_DEVID_HARD_SEC_3916:
	case MPI26_MFGPAGE_DEVID_CFG_SEC_3816:
	case MPI26_MFGPAGE_DEVID_HARD_SEC_3816:
		return MPI26_VERSION;
	}
	return 0;
}