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
struct rsnd_priv {int dummy; } ;
struct rsnd_mod {int dummy; } ;
struct rsnd_dmapp {int /*<<< orphan*/  chcr; } ;
struct rsnd_dma {int /*<<< orphan*/  dst_addr; int /*<<< orphan*/  src_addr; } ;
struct rsnd_dai_stream {int dummy; } ;

/* Variables and functions */
 int /*<<< orphan*/  PDMACHCR ; 
 int /*<<< orphan*/  PDMADAR ; 
 int /*<<< orphan*/  PDMASAR ; 
 struct rsnd_dmapp* rsnd_dma_to_dmapp (struct rsnd_dma*) ; 
 int /*<<< orphan*/  rsnd_dmapp_write (struct rsnd_dma*,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 struct rsnd_dma* rsnd_mod_to_dma (struct rsnd_mod*) ; 

__attribute__((used)) static int rsnd_dmapp_start(struct rsnd_mod *mod,
			    struct rsnd_dai_stream *io,
			    struct rsnd_priv *priv)
{
	struct rsnd_dma *dma = rsnd_mod_to_dma(mod);
	struct rsnd_dmapp *dmapp = rsnd_dma_to_dmapp(dma);

	rsnd_dmapp_write(dma, dma->src_addr,	PDMASAR);
	rsnd_dmapp_write(dma, dma->dst_addr,	PDMADAR);
	rsnd_dmapp_write(dma, dmapp->chcr,	PDMACHCR);

	return 0;
}