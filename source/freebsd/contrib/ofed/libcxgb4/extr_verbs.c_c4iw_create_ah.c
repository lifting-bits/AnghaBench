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
struct ibv_pd {int dummy; } ;
struct ibv_ah_attr {int dummy; } ;
struct ibv_ah {int dummy; } ;

/* Variables and functions */

struct ibv_ah *c4iw_create_ah(struct ibv_pd *pd, struct ibv_ah_attr *attr)
{
	return NULL;
}