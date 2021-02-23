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
typedef  scalar_t__ ULONG ;
typedef  int /*<<< orphan*/  IPropertyBag2 ;
typedef  scalar_t__ HRESULT ;

/* Variables and functions */
 scalar_t__ E_INVALIDARG ; 
 scalar_t__ FAILED (scalar_t__) ; 
 scalar_t__ IPropertyBag2_CountProperties (int /*<<< orphan*/ *,scalar_t__*) ; 
 scalar_t__ S_OK ; 
 int /*<<< orphan*/  ok (int,char*,scalar_t__) ; 

__attribute__((used)) static void test_propertybag_countproperties(IPropertyBag2 *property, ULONG expected_count)
{
    ULONG count = (ULONG)-1;
    HRESULT hr;

    hr = IPropertyBag2_CountProperties(property, NULL);
    ok(hr == E_INVALIDARG, "CountProperties returned unexpected result, hr=%x\n", hr);

    hr = IPropertyBag2_CountProperties(property, &count);
    ok(hr == S_OK, "CountProperties failed, hr=%x\n", hr);

    if (FAILED(hr))
        return;

    ok(count == expected_count, "CountProperties returned invalid value, count=%i\n", count);
}