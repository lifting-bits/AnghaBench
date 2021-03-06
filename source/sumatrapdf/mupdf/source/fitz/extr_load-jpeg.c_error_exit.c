#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_7__   TYPE_2__ ;
typedef  struct TYPE_6__   TYPE_1__ ;

/* Type definitions */
typedef  TYPE_2__* j_common_ptr ;
typedef  int /*<<< orphan*/  fz_context ;
struct TYPE_7__ {TYPE_1__* err; } ;
struct TYPE_6__ {int /*<<< orphan*/  (* format_message ) (TYPE_2__*,char*) ;} ;

/* Variables and functions */
 int /*<<< orphan*/  FZ_ERROR_GENERIC ; 
 int JMSG_LENGTH_MAX ; 
 int /*<<< orphan*/ * JZ_CTX_FROM_CINFO (TYPE_2__*) ; 
 int /*<<< orphan*/  fz_throw (int /*<<< orphan*/ *,int /*<<< orphan*/ ,char*,char*) ; 
 int /*<<< orphan*/  stub1 (TYPE_2__*,char*) ; 

__attribute__((used)) static void error_exit(j_common_ptr cinfo)
{
	char msg[JMSG_LENGTH_MAX];
	fz_context *ctx = JZ_CTX_FROM_CINFO(cinfo);

	cinfo->err->format_message(cinfo, msg);
	fz_throw(ctx, FZ_ERROR_GENERIC, "jpeg error: %s", msg);
}