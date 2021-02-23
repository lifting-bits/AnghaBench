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
typedef  int /*<<< orphan*/  libretro_vfs_implementation_file ;
typedef  scalar_t__ int64_t ;
struct TYPE_3__ {int error_flag; scalar_t__ hfile; } ;
typedef  TYPE_1__ RFILE ;

/* Variables and functions */
 scalar_t__ filestream_truncate_cb (scalar_t__,scalar_t__) ; 
 scalar_t__ retro_vfs_file_truncate_impl (int /*<<< orphan*/ *,scalar_t__) ; 
 scalar_t__ vfs_error_return_value ; 

int64_t filestream_truncate(RFILE *stream, int64_t length)
{
   int64_t output;

   if (filestream_truncate_cb != NULL)
      output = filestream_truncate_cb(stream->hfile, length);
   else
      output = retro_vfs_file_truncate_impl((libretro_vfs_implementation_file*)stream->hfile, length);

   if (output == vfs_error_return_value)
      stream->error_flag = true;

   return output;
}