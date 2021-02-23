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
struct r1conf {int /*<<< orphan*/ * r1buf_pool; } ;

/* Variables and functions */
 int /*<<< orphan*/  allow_barrier (struct r1conf*) ; 
 int /*<<< orphan*/  mempool_destroy (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  wait_barrier (struct r1conf*) ; 

__attribute__((used)) static void close_sync(struct r1conf *conf)
{
	wait_barrier(conf);
	allow_barrier(conf);

	mempool_destroy(conf->r1buf_pool);
	conf->r1buf_pool = NULL;
}