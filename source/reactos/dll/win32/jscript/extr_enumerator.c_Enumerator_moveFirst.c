#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_4__   TYPE_1__ ;

/* Type definitions */
typedef  int /*<<< orphan*/  vdisp_t ;
typedef  int /*<<< orphan*/  script_ctx_t ;
typedef  int /*<<< orphan*/  jsval_t ;
typedef  int /*<<< orphan*/  WORD ;
struct TYPE_4__ {int /*<<< orphan*/  atend; scalar_t__ enumvar; } ;
typedef  int /*<<< orphan*/  HRESULT ;
typedef  TYPE_1__ EnumeratorInstance ;

/* Variables and functions */
 scalar_t__ FAILED (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  FALSE ; 
 int /*<<< orphan*/  IEnumVARIANT_Reset (scalar_t__) ; 
 int /*<<< orphan*/  JS_E_ENUMERATOR_EXPECTED ; 
 int /*<<< orphan*/  S_OK ; 
 int /*<<< orphan*/  TRACE (char*) ; 
 TYPE_1__* enumerator_this (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  enumvar_get_next_item (TYPE_1__*) ; 
 int /*<<< orphan*/  jsval_undefined () ; 
 int /*<<< orphan*/  throw_type_error (int /*<<< orphan*/ *,int /*<<< orphan*/ ,int /*<<< orphan*/ *) ; 

__attribute__((used)) static HRESULT Enumerator_moveFirst(script_ctx_t *ctx, vdisp_t *jsthis, WORD flags, unsigned argc, jsval_t *argv,
        jsval_t *r)
{
    EnumeratorInstance *This;
    HRESULT hres = S_OK;

    TRACE("\n");

    if (!(This = enumerator_this(jsthis)))
        return throw_type_error(ctx, JS_E_ENUMERATOR_EXPECTED, NULL);

    if (This->enumvar)
    {
        hres = IEnumVARIANT_Reset(This->enumvar);
        if (FAILED(hres))
            return hres;

        This->atend = FALSE;
        hres = enumvar_get_next_item(This);
        if(FAILED(hres))
            return hres;
    }

    if (r)
        *r = jsval_undefined();
    return S_OK;
}