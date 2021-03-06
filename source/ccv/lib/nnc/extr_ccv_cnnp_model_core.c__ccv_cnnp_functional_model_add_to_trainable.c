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
typedef  int /*<<< orphan*/  ccv_cnnp_model_t ;
struct TYPE_4__ {int input_size; } ;
struct TYPE_6__ {int sequence_size; TYPE_2__** sequence; TYPE_1__ super; } ;
typedef  TYPE_3__ ccv_cnnp_functional_model_t ;
typedef  int /*<<< orphan*/  ccv_cnnp_add_to_array_f ;
struct TYPE_5__ {int /*<<< orphan*/  model; } ;

/* Variables and functions */
 int /*<<< orphan*/  ccv_cnnp_model_add_to_trainable (int /*<<< orphan*/ ,int /*<<< orphan*/  const,void* const) ; 

__attribute__((used)) static void _ccv_cnnp_functional_model_add_to_trainable(ccv_cnnp_model_t* const super, const ccv_cnnp_add_to_array_f add_to_array, void* const trainables)
{
	ccv_cnnp_functional_model_t* const self = (ccv_cnnp_functional_model_t*)super;
	int i;
	for (i = self->super.input_size; i < self->sequence_size; i++)
		ccv_cnnp_model_add_to_trainable(self->sequence[i]->model, add_to_array, trainables);
}