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
struct d3dx_parameter {scalar_t__ type; int /*<<< orphan*/  data; } ;
struct d3dx9_base_effect {int dummy; } ;
typedef  int /*<<< orphan*/  HRESULT ;
typedef  int /*<<< orphan*/  D3DXHANDLE ;

/* Variables and functions */
 int /*<<< orphan*/  D3DERR_INVALIDCALL ; 
 scalar_t__ D3DXPT_STRING ; 
 int /*<<< orphan*/  WARN (char*) ; 
 struct d3dx_parameter* get_valid_parameter (struct d3dx9_base_effect*,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  set_dirty (struct d3dx_parameter*) ; 
 int /*<<< orphan*/  set_string (int /*<<< orphan*/ ,char const*) ; 

__attribute__((used)) static HRESULT d3dx9_base_effect_set_string(struct d3dx9_base_effect *base,
        D3DXHANDLE parameter, const char *string)
{
    struct d3dx_parameter *param = get_valid_parameter(base, parameter);

    if (param && param->type == D3DXPT_STRING)
    {
        set_dirty(param);
        return set_string(param->data, string);
    }

    WARN("Parameter not found.\n");

    return D3DERR_INVALIDCALL;
}