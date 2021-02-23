#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_6__   TYPE_1__ ;

/* Type definitions */
struct TYPE_6__ {int /*<<< orphan*/ * nvs_ops; } ;
typedef  TYPE_1__ nvstream_t ;
typedef  int /*<<< orphan*/  nvs_header_t ;
typedef  int /*<<< orphan*/  nvlist_t ;
typedef  int /*<<< orphan*/  XDR ;

/* Variables and functions */
 int nvs_operation (TYPE_1__*,int /*<<< orphan*/ *,size_t*) ; 
 int nvs_xdr_create (TYPE_1__*,int /*<<< orphan*/ *,char*,size_t) ; 
 int /*<<< orphan*/  nvs_xdr_destroy (TYPE_1__*) ; 
 int /*<<< orphan*/  nvs_xdr_ops ; 

__attribute__((used)) static int
nvs_xdr(nvstream_t *nvs, nvlist_t *nvl, char *buf, size_t *buflen)
{
	XDR xdr;
	int err;

	nvs->nvs_ops = &nvs_xdr_ops;

	if ((err = nvs_xdr_create(nvs, &xdr, buf + sizeof (nvs_header_t),
	    *buflen - sizeof (nvs_header_t))) != 0)
		return (err);

	err = nvs_operation(nvs, nvl, buflen);

	nvs_xdr_destroy(nvs);

	return (err);
}