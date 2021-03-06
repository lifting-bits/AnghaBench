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
struct TYPE_4__ {scalar_t__ int_refs; scalar_t__ total_refs; } ;
typedef  int /*<<< orphan*/  HRESULT ;
typedef  TYPE_1__ HFONTItem ;
typedef  int /*<<< orphan*/  HFONT ;

/* Variables and functions */
 int /*<<< orphan*/  EnterCriticalSection (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  HFONTItem_Delete (TYPE_1__*) ; 
 int /*<<< orphan*/  LeaveCriticalSection (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  OLEFontImpl_csHFONTLIST ; 
 int /*<<< orphan*/  S_FALSE ; 
 int /*<<< orphan*/  S_OK ; 
 TYPE_1__* find_hfontitem (int /*<<< orphan*/ ) ; 

__attribute__((used)) static HRESULT dec_int_ref(HFONT hfont)
{
    HFONTItem *item;
    HRESULT hr = S_FALSE;

    EnterCriticalSection(&OLEFontImpl_csHFONTLIST);
    item = find_hfontitem(hfont);

    if(item)
    {
        item->int_refs--;
        item->total_refs--;
        if(item->int_refs == 0 && item->total_refs == 0)
            HFONTItem_Delete(item);
        hr = S_OK;
    }
    LeaveCriticalSection(&OLEFontImpl_csHFONTLIST);

    return hr;
}