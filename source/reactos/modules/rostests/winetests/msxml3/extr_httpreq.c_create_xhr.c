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
typedef  int /*<<< orphan*/  IXMLHttpRequest ;
typedef  int /*<<< orphan*/  HRESULT ;

/* Variables and functions */
 int /*<<< orphan*/  CLSCTX_INPROC_SERVER ; 
 int /*<<< orphan*/  CLSID_XMLHTTPRequest ; 
 int /*<<< orphan*/  CoCreateInstance (int /*<<< orphan*/ *,int /*<<< orphan*/ *,int /*<<< orphan*/ ,int /*<<< orphan*/ *,void**) ; 
 int /*<<< orphan*/  IID_IXMLHttpRequest ; 
 scalar_t__ SUCCEEDED (int /*<<< orphan*/ ) ; 

__attribute__((used)) static IXMLHttpRequest *create_xhr(void)
{
    IXMLHttpRequest *ret;
    HRESULT hr;

    hr = CoCreateInstance(&CLSID_XMLHTTPRequest, NULL, CLSCTX_INPROC_SERVER,
        &IID_IXMLHttpRequest, (void**)&ret);

    return SUCCEEDED(hr) ? ret : NULL;
}