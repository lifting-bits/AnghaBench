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
typedef  int /*<<< orphan*/  pdf_obj ;
typedef  int /*<<< orphan*/  pdf_keystroke_event ;
typedef  int /*<<< orphan*/  pdf_js ;
struct TYPE_4__ {int /*<<< orphan*/ * js; } ;
typedef  TYPE_1__ pdf_document ;
typedef  int /*<<< orphan*/  fz_context ;

/* Variables and functions */
 int /*<<< orphan*/ * pdf_dict_getp (int /*<<< orphan*/ *,int /*<<< orphan*/ *,char*) ; 
 int /*<<< orphan*/  pdf_execute_js_action (int /*<<< orphan*/ *,TYPE_1__*,int /*<<< orphan*/ *,char*,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  pdf_js_event_init_keystroke (int /*<<< orphan*/ *,int /*<<< orphan*/ *,int /*<<< orphan*/ *) ; 
 int pdf_js_event_result_keystroke (int /*<<< orphan*/ *,int /*<<< orphan*/ *) ; 

int pdf_field_event_keystroke(fz_context *ctx, pdf_document *doc, pdf_obj *field, pdf_keystroke_event *evt)
{
	pdf_js *js = doc->js;
	if (js)
	{
		pdf_obj *action = pdf_dict_getp(ctx, field, "AA/K/JS");
		if (action)
		{
			pdf_js_event_init_keystroke(js, field, evt);
			pdf_execute_js_action(ctx, doc, field, "AA/K/JS", action);
			return pdf_js_event_result_keystroke(js, evt);
		}
	}
	return 1;
}