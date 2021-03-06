#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_2__   TYPE_1__ ;

/* Type definitions */
typedef  int /*<<< orphan*/  u8 ;
struct TYPE_2__ {int /*<<< orphan*/  id; } ;
struct cfsrvl {TYPE_1__ dev_info; } ;
struct cflayer {int dummy; } ;

/* Variables and functions */
 struct cfsrvl* container_obj (struct cflayer*) ; 

u8 cfsrvl_getphyid(struct cflayer *layer)
{
	struct cfsrvl *servl = container_obj(layer);
	return servl->dev_info.id;
}