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
typedef  int uint32_t ;
typedef  int /*<<< orphan*/  result_vec ;

/* Variables and functions */
 int /*<<< orphan*/  IOCTL_FSA_OPENFILE ; 
 int IOS_Ioctl (scalar_t__,int /*<<< orphan*/ ,int*,int,int*,int) ; 
 int /*<<< orphan*/  free (int*) ; 
 scalar_t__ iosuhaxHandle ; 
 scalar_t__ memalign (int,int) ; 
 int /*<<< orphan*/  strcpy (char*,char const*) ; 
 int strlen (char const*) ; 

int IOSUHAX_FSA_OpenFile(int fsaFd, const char* path, const char* mode, int* outHandle)
{
    if(iosuhaxHandle < 0)
        return iosuhaxHandle;

    if(!path || !mode || !outHandle)
        return -1;

    const int input_cnt = 3;

    int io_buf_size = sizeof(uint32_t) * input_cnt + strlen(path) + strlen(mode) + 2;

    uint32_t *io_buf = (uint32_t*)memalign(0x20, io_buf_size);
    if(!io_buf)
        return -2;

    io_buf[0] = fsaFd;
    io_buf[1] = sizeof(uint32_t) * input_cnt;
    io_buf[2] = io_buf[1] + strlen(path) + 1;
    strcpy(((char*)io_buf) + io_buf[1],  path);
    strcpy(((char*)io_buf) + io_buf[2],  mode);

    int result_vec[2];

    int res = IOS_Ioctl(iosuhaxHandle, IOCTL_FSA_OPENFILE, io_buf, io_buf_size, result_vec, sizeof(result_vec));
    if(res < 0)
    {
        free(io_buf);
        return res;
    }

    *outHandle = result_vec[1];
    free(io_buf);
    return result_vec[0];
}