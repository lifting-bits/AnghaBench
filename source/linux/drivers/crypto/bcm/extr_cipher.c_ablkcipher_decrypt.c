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
struct ablkcipher_request {int /*<<< orphan*/  nbytes; } ;

/* Variables and functions */
 int ablkcipher_enqueue (struct ablkcipher_request*,int) ; 
 int /*<<< orphan*/  flow_log (char*,int /*<<< orphan*/ ) ; 

__attribute__((used)) static int ablkcipher_decrypt(struct ablkcipher_request *req)
{
	flow_log("ablkcipher_decrypt() nbytes:%u\n", req->nbytes);
	return ablkcipher_enqueue(req, false);
}