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
struct rpc_nonce_packet {int dummy; } ;
struct connection {int dummy; } ;

/* Variables and functions */
 int rpcs_init_fake_crypto (struct connection*) ; 

int rpcs_init_crypto (struct connection *c, struct rpc_nonce_packet *P) {
  return rpcs_init_fake_crypto (c);
}