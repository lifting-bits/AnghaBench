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
typedef  int /*<<< orphan*/  ov_callbacks ;
typedef  int /*<<< orphan*/  OggVorbis_File ;

/* Variables and functions */
 int _ov_open1 (void*,int /*<<< orphan*/ *,char*,long,int /*<<< orphan*/ ) ; 
 int _ov_open2 (int /*<<< orphan*/ *) ; 

int ov_open_callbacks(void *f,OggVorbis_File *vf,char *initial,long ibytes,
    ov_callbacks callbacks){
  int ret=_ov_open1(f,vf,initial,ibytes,callbacks);
  if(ret)return ret;
  return _ov_open2(vf);
}