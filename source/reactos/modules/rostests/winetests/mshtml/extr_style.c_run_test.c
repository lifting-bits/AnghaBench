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
typedef  int /*<<< orphan*/  (* style_test_t ) (int /*<<< orphan*/ *) ;
typedef  int ULONG ;
typedef  int /*<<< orphan*/  MSG ;
typedef  int /*<<< orphan*/  IUnknown ;
typedef  int /*<<< orphan*/  IHTMLDocument2 ;

/* Variables and functions */
 int /*<<< orphan*/  DispatchMessageW (int /*<<< orphan*/ *) ; 
 scalar_t__ GetMessageW (int /*<<< orphan*/ *,int /*<<< orphan*/ *,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int IHTMLDocument2_Release (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  IID_IPropertyNotifySink ; 
 int /*<<< orphan*/  PropertyNotifySink ; 
 int /*<<< orphan*/  TranslateMessage (int /*<<< orphan*/ *) ; 
 scalar_t__ broken (int) ; 
 int /*<<< orphan*/ * create_doc_with_string (char const*) ; 
 int /*<<< orphan*/  do_advise (int /*<<< orphan*/ *,int /*<<< orphan*/ *,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  doc_complete ; 
 int /*<<< orphan*/  ok (int,char*,int) ; 

__attribute__((used)) static void run_test(const char *str, style_test_t test)
{
    IHTMLDocument2 *doc;
    ULONG ref;
    MSG msg;

    doc = create_doc_with_string(str);
    if(!doc)
        return;

    do_advise((IUnknown*)doc, &IID_IPropertyNotifySink, (IUnknown*)&PropertyNotifySink);

    while(!doc_complete && GetMessageW(&msg, NULL, 0, 0)) {
        TranslateMessage(&msg);
        DispatchMessageW(&msg);
    }

    test(doc);

    ref = IHTMLDocument2_Release(doc);
    ok(!ref || broken(ref == 1), /* Vista */
       "ref = %d\n", ref);
}