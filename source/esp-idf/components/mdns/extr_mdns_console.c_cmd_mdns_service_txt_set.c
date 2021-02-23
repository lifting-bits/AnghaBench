#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_10__   TYPE_5__ ;
typedef  struct TYPE_9__   TYPE_4__ ;
typedef  struct TYPE_8__   TYPE_3__ ;
typedef  struct TYPE_7__   TYPE_2__ ;
typedef  struct TYPE_6__   TYPE_1__ ;

/* Type definitions */
struct TYPE_10__ {TYPE_4__* value; TYPE_3__* var; TYPE_2__* proto; TYPE_1__* service; int /*<<< orphan*/  end; } ;
struct TYPE_9__ {int /*<<< orphan*/ * sval; } ;
struct TYPE_8__ {int /*<<< orphan*/ * sval; } ;
struct TYPE_7__ {int /*<<< orphan*/ * sval; } ;
struct TYPE_6__ {int /*<<< orphan*/ * sval; } ;

/* Variables and functions */
 int /*<<< orphan*/  ESP_ERROR_CHECK (int /*<<< orphan*/ ) ; 
 int arg_parse (int,char**,void**) ; 
 int /*<<< orphan*/  arg_print_errors (int /*<<< orphan*/ ,int /*<<< orphan*/ ,char*) ; 
 int /*<<< orphan*/  mdns_service_txt_item_set (int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 TYPE_5__ mdns_txt_set_args ; 
 int /*<<< orphan*/  printf (char*) ; 
 int /*<<< orphan*/  stderr ; 

__attribute__((used)) static int cmd_mdns_service_txt_set(int argc, char** argv)
{
    int nerrors = arg_parse(argc, argv, (void**) &mdns_txt_set_args);
    if (nerrors != 0) {
        arg_print_errors(stderr, mdns_txt_set_args.end, argv[0]);
        return 1;
    }

    if (!mdns_txt_set_args.service->sval[0] || !mdns_txt_set_args.proto->sval[0] || !mdns_txt_set_args.var->sval[0]) {
        printf("ERROR: Bad arguments!\n");
        return 1;
    }

    ESP_ERROR_CHECK( mdns_service_txt_item_set(mdns_txt_set_args.service->sval[0], mdns_txt_set_args.proto->sval[0], mdns_txt_set_args.var->sval[0], mdns_txt_set_args.value->sval[0]) );
    return 0;
}