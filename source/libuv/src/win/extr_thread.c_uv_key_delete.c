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
struct TYPE_3__ {int /*<<< orphan*/  tls_index; } ;
typedef  TYPE_1__ uv_key_t ;

/* Variables and functions */
 scalar_t__ FALSE ; 
 int /*<<< orphan*/  TLS_OUT_OF_INDEXES ; 
 scalar_t__ TlsFree (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  abort () ; 

void uv_key_delete(uv_key_t* key) {
  if (TlsFree(key->tls_index) == FALSE)
    abort();
  key->tls_index = TLS_OUT_OF_INDEXES;
}