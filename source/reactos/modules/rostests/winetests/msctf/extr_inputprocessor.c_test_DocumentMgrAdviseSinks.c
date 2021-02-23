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
typedef  int /*<<< orphan*/  IUnknown ;
typedef  int /*<<< orphan*/  ITfSource ;
typedef  scalar_t__ HRESULT ;

/* Variables and functions */
 int /*<<< orphan*/  IID_ITfSource ; 
 int /*<<< orphan*/  IID_ITfTransitoryExtensionSink ; 
 scalar_t__ ITfDocumentMgr_QueryInterface (int /*<<< orphan*/ ,int /*<<< orphan*/ *,void**) ; 
 scalar_t__ ITfSource_AdviseSink (int /*<<< orphan*/ *,int /*<<< orphan*/ *,int /*<<< orphan*/ *,scalar_t__*) ; 
 int /*<<< orphan*/  ITfSource_Release (int /*<<< orphan*/ *) ; 
 scalar_t__ S_OK ; 
 int /*<<< orphan*/  TfTransitoryExtensionSink ; 
 scalar_t__ dmSinkCookie ; 
 int /*<<< orphan*/  g_dm ; 
 int /*<<< orphan*/  ok (int,char*) ; 

__attribute__((used)) static void test_DocumentMgrAdviseSinks(void)
{
    ITfSource *source;
    HRESULT hr;

    hr = ITfDocumentMgr_QueryInterface(g_dm, &IID_ITfSource, (void**)&source);
    ok(hr == S_OK,"Failed to get IID_ITfSource for DocumentMgr\n");

    dmSinkCookie = 0;
    hr = ITfSource_AdviseSink(source, &IID_ITfTransitoryExtensionSink, (IUnknown*)&TfTransitoryExtensionSink, &dmSinkCookie);
    ok(hr == S_OK,"Failed to Advise Sink\n");

    ITfSource_Release(source);
}