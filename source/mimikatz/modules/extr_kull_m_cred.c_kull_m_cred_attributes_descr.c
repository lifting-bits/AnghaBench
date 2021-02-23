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
typedef  int /*<<< orphan*/  PKULL_M_CRED_ATTRIBUTE ;
typedef  size_t DWORD ;

/* Variables and functions */
 int /*<<< orphan*/  kull_m_cred_attribute_descr (size_t,int /*<<< orphan*/ ) ; 

void kull_m_cred_attributes_descr(DWORD level, PKULL_M_CRED_ATTRIBUTE *Attributes, DWORD count)
{
	DWORD i;
	if(count && Attributes)
		for(i = 0; i < count; i++)
			kull_m_cred_attribute_descr(level, Attributes[i]);
}