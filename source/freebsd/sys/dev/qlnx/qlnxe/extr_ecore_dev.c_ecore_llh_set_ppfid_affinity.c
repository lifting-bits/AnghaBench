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
typedef  int u8 ;
typedef  int u32 ;
struct ecore_ptt {int dummy; } ;
struct ecore_hwfn {int dummy; } ;
struct ecore_dev {int iwarp_affin; } ;
typedef  enum ecore_eng { ____Placeholder_ecore_eng } ecore_eng ;
typedef  enum _ecore_status_t { ____Placeholder__ecore_status_t } _ecore_status_t ;

/* Variables and functions */
 int /*<<< orphan*/  DP_NOTICE (struct ecore_dev*,int,char*,int) ; 
 int ECORE_AGAIN ; 
#define  ECORE_BOTH_ENG 130 
#define  ECORE_ENG0 129 
#define  ECORE_ENG1 128 
 int ECORE_INVAL ; 
 int /*<<< orphan*/  ECORE_IS_CMT (struct ecore_dev*) ; 
 scalar_t__ ECORE_IS_IWARP_PERSONALITY (struct ecore_hwfn*) ; 
 struct ecore_hwfn* ECORE_LEADING_HWFN (struct ecore_dev*) ; 
 int ECORE_SUCCESS ; 
 int NIG_REG_PPF_TO_ENGINE_SEL ; 
 int /*<<< orphan*/  NIG_REG_PPF_TO_ENGINE_SEL_NON_ROCE ; 
 struct ecore_ptt* OSAL_NULL ; 
 int /*<<< orphan*/  SET_FIELD (int,int /*<<< orphan*/ ,int) ; 
 int ecore_abs_ppfid (struct ecore_dev*,int,int*) ; 
 struct ecore_ptt* ecore_ptt_acquire (struct ecore_hwfn*) ; 
 int /*<<< orphan*/  ecore_ptt_release (struct ecore_hwfn*,struct ecore_ptt*) ; 
 int ecore_rd (struct ecore_hwfn*,struct ecore_ptt*,int) ; 
 int /*<<< orphan*/  ecore_wr (struct ecore_hwfn*,struct ecore_ptt*,int,int) ; 

enum _ecore_status_t ecore_llh_set_ppfid_affinity(struct ecore_dev *p_dev,
						  u8 ppfid, enum ecore_eng eng)
{
	struct ecore_hwfn *p_hwfn = ECORE_LEADING_HWFN(p_dev);
	struct ecore_ptt *p_ptt = ecore_ptt_acquire(p_hwfn);
	u32 addr, val, eng_sel;
	enum _ecore_status_t rc = ECORE_SUCCESS;
	u8 abs_ppfid;

	if (p_ptt == OSAL_NULL)
		return ECORE_AGAIN;

	if (!ECORE_IS_CMT(p_dev))
		goto out;

	rc = ecore_abs_ppfid(p_dev, ppfid, &abs_ppfid);
	if (rc != ECORE_SUCCESS)
		goto out;

	switch (eng) {
	case ECORE_ENG0:
		eng_sel = 0;
		break;
	case ECORE_ENG1:
		eng_sel = 1;
		break;
	case ECORE_BOTH_ENG:
		eng_sel = 2;
		break;
	default:
		DP_NOTICE(p_dev, false,
			  "Invalid affinity value for ppfid [%d]\n", eng);
		rc = ECORE_INVAL;
		goto out;
	}

	addr = NIG_REG_PPF_TO_ENGINE_SEL + abs_ppfid * 0x4;
	val = ecore_rd(p_hwfn, p_ptt, addr);
	SET_FIELD(val, NIG_REG_PPF_TO_ENGINE_SEL_NON_ROCE, eng_sel);
	ecore_wr(p_hwfn, p_ptt, addr, val);

	/* The iWARP affinity is set as the affinity of ppfid 0 */
	if (!ppfid && ECORE_IS_IWARP_PERSONALITY(p_hwfn))
		p_dev->iwarp_affin = (eng == ECORE_ENG1) ? 1 : 0;
out:
	ecore_ptt_release(p_hwfn, p_ptt);

	return rc;
}