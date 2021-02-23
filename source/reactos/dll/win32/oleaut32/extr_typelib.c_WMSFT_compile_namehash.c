#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_5__   TYPE_2__ ;
typedef  struct TYPE_4__   TYPE_1__ ;

/* Type definitions */
struct TYPE_4__ {int len; int /*<<< orphan*/  data; } ;
struct TYPE_5__ {TYPE_1__ namehash_seg; } ;
typedef  TYPE_2__ WMSFT_TLBFile ;
typedef  int /*<<< orphan*/  ITypeLibImpl ;

/* Variables and functions */
 int /*<<< orphan*/  heap_alloc (int) ; 
 int /*<<< orphan*/  memset (int /*<<< orphan*/ ,int,int) ; 

__attribute__((used)) static void WMSFT_compile_namehash(ITypeLibImpl *This, WMSFT_TLBFile *file)
{
    file->namehash_seg.len = 0x200;
    file->namehash_seg.data = heap_alloc(file->namehash_seg.len);
    memset(file->namehash_seg.data, 0xFF, file->namehash_seg.len);
}