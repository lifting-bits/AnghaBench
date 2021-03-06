#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_8__   TYPE_3__ ;
typedef  struct TYPE_7__   TYPE_2__ ;
typedef  struct TYPE_6__   TYPE_1__ ;

/* Type definitions */
struct TYPE_6__ {TYPE_2__* backend_ctx; } ;
typedef  TYPE_1__ hashcat_ctx_t ;
struct TYPE_7__ {scalar_t__ cuda; } ;
typedef  TYPE_2__ backend_ctx_t ;
struct TYPE_8__ {scalar_t__ (* cuModuleLoadDataEx ) (int /*<<< orphan*/ *,void const*,unsigned int,int /*<<< orphan*/ *,void**) ;scalar_t__ const (* cuGetErrorString ) (scalar_t__ const,char const**) ;} ;
typedef  scalar_t__ CUresult ;
typedef  int /*<<< orphan*/  CUmodule ;
typedef  int /*<<< orphan*/  CUjit_option ;
typedef  TYPE_3__ CUDA_PTR ;

/* Variables and functions */
 scalar_t__ const CUDA_SUCCESS ; 
 int /*<<< orphan*/  event_log_error (TYPE_1__*,char*,scalar_t__ const) ; 
 scalar_t__ stub1 (int /*<<< orphan*/ *,void const*,unsigned int,int /*<<< orphan*/ *,void**) ; 
 scalar_t__ const stub2 (scalar_t__ const,char const**) ; 

int hc_cuModuleLoadDataEx (hashcat_ctx_t *hashcat_ctx, CUmodule *module, const void *image, unsigned int numOptions, CUjit_option *options, void **optionValues)
{
  backend_ctx_t *backend_ctx = hashcat_ctx->backend_ctx;

  CUDA_PTR *cuda = (CUDA_PTR *) backend_ctx->cuda;

  const CUresult CU_err = cuda->cuModuleLoadDataEx (module, image, numOptions, options, optionValues);

  if (CU_err != CUDA_SUCCESS)
  {
    const char *pStr = NULL;

    if (cuda->cuGetErrorString (CU_err, &pStr) == CUDA_SUCCESS)
    {
      event_log_error (hashcat_ctx, "cuModuleLoadDataEx(): %s", pStr);
    }
    else
    {
      event_log_error (hashcat_ctx, "cuModuleLoadDataEx(): %d", CU_err);
    }

    return -1;
  }

  return 0;
}