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
struct ahash_request {int dummy; } ;

/* Variables and functions */
 int atmel_sha_finup (struct ahash_request*) ; 
 scalar_t__ atmel_sha_init (struct ahash_request*) ; 

__attribute__((used)) static int atmel_sha_digest(struct ahash_request *req)
{
	return atmel_sha_init(req) ?: atmel_sha_finup(req);
}