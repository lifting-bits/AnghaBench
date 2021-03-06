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
typedef  int /*<<< orphan*/  SHA512_CTX ;
typedef  int /*<<< orphan*/  SHA384_CTX ;

/* Variables and functions */
 int /*<<< orphan*/  SHA512_Update (int /*<<< orphan*/ *,void const*,size_t) ; 

void
SHA384_Update(SHA384_CTX * ctx, const void *in, size_t len)
{

	SHA512_Update((SHA512_CTX *)ctx, in, len);
}