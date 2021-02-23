#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_3__   TYPE_1__ ;

/* Type definitions */
struct TYPE_3__ {scalar_t__* bitcount; int /*<<< orphan*/  buffer; int /*<<< orphan*/  state; } ;
typedef  TYPE_1__ isc_sha512_t ;

/* Variables and functions */
 int /*<<< orphan*/  ISC_SHA512_BLOCK_LENGTH ; 
 int /*<<< orphan*/  ISC_SHA512_DIGESTLENGTH ; 
 int /*<<< orphan*/  memcpy (int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  memset (int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  sha512_initial_hash_value ; 

void
isc_sha512_init(isc_sha512_t *context) {
	if (context == (isc_sha512_t *)0) {
		return;
	}
	memcpy(context->state, sha512_initial_hash_value,
	       ISC_SHA512_DIGESTLENGTH);
	memset(context->buffer, 0, ISC_SHA512_BLOCK_LENGTH);
	context->bitcount[0] = context->bitcount[1] =  0;
}