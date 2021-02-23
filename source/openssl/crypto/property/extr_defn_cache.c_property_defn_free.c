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
struct TYPE_4__ {int /*<<< orphan*/  defn; } ;
typedef  TYPE_1__ PROPERTY_DEFN_ELEM ;

/* Variables and functions */
 int /*<<< orphan*/  OPENSSL_free (TYPE_1__*) ; 
 int /*<<< orphan*/  ossl_property_free (int /*<<< orphan*/ ) ; 

__attribute__((used)) static void property_defn_free(PROPERTY_DEFN_ELEM *elem)
{
    ossl_property_free(elem->defn);
    OPENSSL_free(elem);
}