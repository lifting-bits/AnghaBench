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
typedef  int /*<<< orphan*/  REFIID ;
typedef  int /*<<< orphan*/  HRESULT ;

/* Variables and functions */
 int /*<<< orphan*/  GCEReader_Vtbl ; 
 int /*<<< orphan*/  MetadataReader_Create (int /*<<< orphan*/ *,int /*<<< orphan*/ ,void**) ; 

HRESULT GCEReader_CreateInstance(REFIID iid, void **ppv)
{
    return MetadataReader_Create(&GCEReader_Vtbl, iid, ppv);
}