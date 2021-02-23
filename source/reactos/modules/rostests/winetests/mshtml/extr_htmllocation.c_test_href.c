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
struct location_test {scalar_t__ href; int /*<<< orphan*/  name; } ;
typedef  int /*<<< orphan*/  IHTMLLocation ;
typedef  scalar_t__ HRESULT ;
typedef  int /*<<< orphan*/  BSTR ;

/* Variables and functions */
 scalar_t__ E_POINTER ; 
 scalar_t__ IHTMLLocation_get_href (int /*<<< orphan*/ *,int /*<<< orphan*/ *) ; 
 scalar_t__ IHTMLLocation_toString (int /*<<< orphan*/ *,int /*<<< orphan*/ *) ; 
 scalar_t__ S_OK ; 
 int /*<<< orphan*/  SysFreeString (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  ok (int,char*,int /*<<< orphan*/ ,scalar_t__,...) ; 
 int str_eq_wa (int /*<<< orphan*/ ,scalar_t__) ; 
 scalar_t__ wine_dbgstr_w (int /*<<< orphan*/ ) ; 

__attribute__((used)) static void test_href(IHTMLLocation *loc, const struct location_test *test)
{
    HRESULT hres;
    BSTR str;

    hres = IHTMLLocation_get_href(loc, NULL);
    ok(hres == E_POINTER,
            "%s: get_href should have failed with E_POINTER (0x%08x), was: 0x%08x\n",
            test->name, E_POINTER, hres);

    hres = IHTMLLocation_get_href(loc, &str);
    ok(hres == S_OK, "%s: get_href failed: 0x%08x\n", test->name, hres);
    if(hres == S_OK)
        ok(str_eq_wa(str, test->href),
                "%s: expected retrieved href to be L\"%s\", was: %s\n",
                test->name, test->href, wine_dbgstr_w(str));
    SysFreeString(str);

    hres = IHTMLLocation_toString(loc, &str);
    ok(hres == S_OK, "%s: toString failed: 0x%08x\n", test->name, hres);
    ok(str_eq_wa(str, test->href), "%s: toString returned %s, expected %s\n",
       test->name, wine_dbgstr_w(str), test->href);
    SysFreeString(str);
}