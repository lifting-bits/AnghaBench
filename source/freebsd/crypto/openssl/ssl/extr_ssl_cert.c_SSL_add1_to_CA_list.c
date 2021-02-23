#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_3__   TYPE_1__ ;

/* Type definitions */
typedef  int /*<<< orphan*/  X509 ;
struct TYPE_3__ {int /*<<< orphan*/  ca_names; } ;
typedef  TYPE_1__ SSL ;

/* Variables and functions */
 int add_ca_name (int /*<<< orphan*/ *,int /*<<< orphan*/  const*) ; 

int SSL_add1_to_CA_list(SSL *ssl, const X509 *x)
{
    return add_ca_name(&ssl->ca_names, x);
}