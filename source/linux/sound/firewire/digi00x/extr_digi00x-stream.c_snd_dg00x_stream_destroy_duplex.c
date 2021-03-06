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
struct snd_dg00x {int /*<<< orphan*/  tx_stream; int /*<<< orphan*/  rx_stream; int /*<<< orphan*/  domain; } ;

/* Variables and functions */
 int /*<<< orphan*/  amdtp_domain_destroy (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  destroy_stream (struct snd_dg00x*,int /*<<< orphan*/ *) ; 

void snd_dg00x_stream_destroy_duplex(struct snd_dg00x *dg00x)
{
	amdtp_domain_destroy(&dg00x->domain);

	destroy_stream(dg00x, &dg00x->rx_stream);
	destroy_stream(dg00x, &dg00x->tx_stream);
}