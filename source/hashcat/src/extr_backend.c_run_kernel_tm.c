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
typedef  int u64 ;
struct TYPE_3__ {int is_cuda; int is_opencl; int /*<<< orphan*/  opencl_command_queue; int /*<<< orphan*/  opencl_kernel_tm; int /*<<< orphan*/  cuda_stream; int /*<<< orphan*/  kernel_params_tm; int /*<<< orphan*/  cuda_function_tm; int /*<<< orphan*/  kernel_wgs_tm; } ;
typedef  TYPE_1__ hc_device_param_t ;
typedef  int /*<<< orphan*/  hashcat_ctx_t ;
typedef  int /*<<< orphan*/  cl_kernel ;
typedef  int /*<<< orphan*/  CUfunction ;

/* Variables and functions */
 int MIN (int const,int /*<<< orphan*/ ) ; 
 int hc_clEnqueueNDRangeKernel (int /*<<< orphan*/ *,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int,int /*<<< orphan*/ *,size_t const*,size_t const*,int /*<<< orphan*/ ,int /*<<< orphan*/ *,int /*<<< orphan*/ *) ; 
 int hc_clFinish (int /*<<< orphan*/ *,int /*<<< orphan*/ ) ; 
 int hc_clFlush (int /*<<< orphan*/ *,int /*<<< orphan*/ ) ; 
 int hc_cuLaunchKernel (int /*<<< orphan*/ *,int /*<<< orphan*/ ,int const,int,int,int const,int,int,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ *) ; 
 int hc_cuStreamSynchronize (int /*<<< orphan*/ *,int /*<<< orphan*/ ) ; 

int run_kernel_tm (hashcat_ctx_t *hashcat_ctx, hc_device_param_t *device_param)
{
  const u64 num_elements = 1024; // fixed

  const u64 kernel_threads = MIN (num_elements, device_param->kernel_wgs_tm);

  if (device_param->is_cuda == true)
  {
    CUfunction cuda_function = device_param->cuda_function_tm;

    if (hc_cuLaunchKernel (hashcat_ctx, cuda_function, num_elements / kernel_threads, 1, 1, kernel_threads, 1, 1, 0, device_param->cuda_stream, device_param->kernel_params_tm, NULL) == -1) return -1;

    if (hc_cuStreamSynchronize (hashcat_ctx, device_param->cuda_stream) == -1) return -1;
  }

  if (device_param->is_opencl == true)
  {
    cl_kernel cuda_kernel = device_param->opencl_kernel_tm;

    const size_t global_work_size[3] = { num_elements,    1, 1 };
    const size_t local_work_size[3]  = { kernel_threads,  1, 1 };

    if (hc_clEnqueueNDRangeKernel (hashcat_ctx, device_param->opencl_command_queue, cuda_kernel, 1, NULL, global_work_size, local_work_size, 0, NULL, NULL) == -1) return -1;

    if (hc_clFlush (hashcat_ctx, device_param->opencl_command_queue) == -1) return -1;

    if (hc_clFinish (hashcat_ctx, device_param->opencl_command_queue) == -1) return -1;
  }

  return 0;
}