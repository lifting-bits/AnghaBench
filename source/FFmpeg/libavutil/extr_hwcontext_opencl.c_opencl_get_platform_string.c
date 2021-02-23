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
typedef  int /*<<< orphan*/  cl_platform_info ;
typedef  int /*<<< orphan*/  cl_platform_id ;
typedef  scalar_t__ cl_int ;

/* Variables and functions */
 scalar_t__ CL_SUCCESS ; 
 int /*<<< orphan*/  av_assert0 (int) ; 
 int /*<<< orphan*/  av_free (char*) ; 
 char* av_malloc (size_t) ; 
 scalar_t__ clGetPlatformInfo (int /*<<< orphan*/ ,int /*<<< orphan*/ ,size_t,char*,size_t*) ; 
 int strlen (char*) ; 

__attribute__((used)) static char *opencl_get_platform_string(cl_platform_id platform_id,
                                        cl_platform_info key)
{
    char *str;
    size_t size;
    cl_int cle;
    cle = clGetPlatformInfo(platform_id, key, 0, NULL, &size);
    if (cle != CL_SUCCESS)
        return NULL;
    str = av_malloc(size);
    if (!str)
        return NULL;
    cle = clGetPlatformInfo(platform_id, key, size, str, &size);
    if (cle != CL_SUCCESS) {
        av_free(str);
        return NULL;
    }
    av_assert0(strlen(str) + 1 == size);
    return str;
}