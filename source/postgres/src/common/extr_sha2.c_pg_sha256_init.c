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
struct TYPE_3__ {scalar_t__ bitcount; int /*<<< orphan*/  buffer; int /*<<< orphan*/  state; } ;
typedef  TYPE_1__ pg_sha256_ctx ;

/* Variables and functions */
 int /*<<< orphan*/  PG_SHA256_BLOCK_LENGTH ; 
 int /*<<< orphan*/  PG_SHA256_DIGEST_LENGTH ; 
 int /*<<< orphan*/  memcpy (int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  memset (int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  sha256_initial_hash_value ; 

void
pg_sha256_init(pg_sha256_ctx *context)
{
	if (context == NULL)
		return;
	memcpy(context->state, sha256_initial_hash_value, PG_SHA256_DIGEST_LENGTH);
	memset(context->buffer, 0, PG_SHA256_BLOCK_LENGTH);
	context->bitcount = 0;
}