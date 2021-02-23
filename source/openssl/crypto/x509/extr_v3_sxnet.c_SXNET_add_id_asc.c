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
typedef  int /*<<< orphan*/  SXNET ;
typedef  int /*<<< orphan*/  ASN1_INTEGER ;

/* Variables and functions */
 int SXNET_add_id_INTEGER (int /*<<< orphan*/ **,int /*<<< orphan*/ *,char const*,int) ; 
 int /*<<< orphan*/  X509V3_F_SXNET_ADD_ID_ASC ; 
 int /*<<< orphan*/  X509V3_R_ERROR_CONVERTING_ZONE ; 
 int /*<<< orphan*/  X509V3err (int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/ * s2i_ASN1_INTEGER (int /*<<< orphan*/ *,char const*) ; 

int SXNET_add_id_asc(SXNET **psx, const char *zone, const char *user, int userlen)
{
    ASN1_INTEGER *izone;

    if ((izone = s2i_ASN1_INTEGER(NULL, zone)) == NULL) {
        X509V3err(X509V3_F_SXNET_ADD_ID_ASC, X509V3_R_ERROR_CONVERTING_ZONE);
        return 0;
    }
    return SXNET_add_id_INTEGER(psx, izone, user, userlen);
}