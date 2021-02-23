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
typedef  scalar_t__ ULONG ;
typedef  scalar_t__ UCHAR ;
typedef  int /*<<< orphan*/ * PULONG ;
typedef  int /*<<< orphan*/ * PSID ;

/* Variables and functions */
 int /*<<< orphan*/ * MIDL_user_allocate (scalar_t__) ; 
 int /*<<< orphan*/  RtlIdentifierAuthoritySid (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  RtlInitializeSid (int /*<<< orphan*/ *,int /*<<< orphan*/ ,scalar_t__) ; 
 scalar_t__ RtlLengthRequiredSid (scalar_t__) ; 
 scalar_t__* RtlSubAuthorityCountSid (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/ * RtlSubAuthoritySid (int /*<<< orphan*/ *,scalar_t__) ; 

__attribute__((used)) static PSID
CreateDomainSidFromAccountSid(PSID AccountSid)
{
    UCHAR RidCount;
    PSID DomainSid;
    ULONG i;
    ULONG DstSidSize;
    PULONG p, q;

    RidCount = *RtlSubAuthorityCountSid(AccountSid);
    if (RidCount > 0)
        RidCount--;

    DstSidSize = RtlLengthRequiredSid(RidCount);

    DomainSid = MIDL_user_allocate(DstSidSize);
    if (DomainSid == NULL)
        return NULL;

    RtlInitializeSid(DomainSid,
                     RtlIdentifierAuthoritySid(AccountSid),
                     RidCount);

    for (i = 0; i < (ULONG)RidCount; i++)
    {
        p = RtlSubAuthoritySid(AccountSid, i);
        q = RtlSubAuthoritySid(DomainSid, i);
        *q = *p;
    }

    return DomainSid;
}