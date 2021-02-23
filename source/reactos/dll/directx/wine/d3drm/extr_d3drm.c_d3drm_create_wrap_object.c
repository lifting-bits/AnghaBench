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
struct d3drm_wrap {int /*<<< orphan*/  IDirect3DRMWrap_iface; } ;
typedef  int /*<<< orphan*/  IDirect3DRM ;
typedef  int /*<<< orphan*/  HRESULT ;

/* Variables and functions */
 scalar_t__ FAILED (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  d3drm_wrap_create (struct d3drm_wrap**,int /*<<< orphan*/ *) ; 

__attribute__((used)) static HRESULT d3drm_create_wrap_object(void **object, IDirect3DRM *d3drm)
{
    struct d3drm_wrap *wrap;
    HRESULT hr;

    if (FAILED(hr = d3drm_wrap_create(&wrap, d3drm)))
        return hr;

    *object = &wrap->IDirect3DRMWrap_iface;

    return hr;
}