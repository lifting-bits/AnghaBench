#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_6__   TYPE_3__ ;
typedef  struct TYPE_5__   TYPE_2__ ;
typedef  struct TYPE_4__   TYPE_1__ ;

/* Type definitions */
typedef  enum gfx_wrap_type { ____Placeholder_gfx_wrap_type } gfx_wrap_type ;
struct TYPE_6__ {TYPE_2__* shader; } ;
typedef  TYPE_3__ cg_shader_data_t ;
struct TYPE_5__ {TYPE_1__* pass; } ;
struct TYPE_4__ {int wrap; } ;

/* Variables and functions */
 int RARCH_WRAP_BORDER ; 

__attribute__((used)) static enum gfx_wrap_type gl_cg_wrap_type(void *data, unsigned idx)
{
   cg_shader_data_t *cg = (cg_shader_data_t*)data;
   if (cg && idx)
      return cg->shader->pass[idx - 1].wrap;
   return RARCH_WRAP_BORDER;
}