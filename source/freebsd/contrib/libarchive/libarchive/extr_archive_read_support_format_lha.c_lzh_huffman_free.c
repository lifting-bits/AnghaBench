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
struct huffman {int /*<<< orphan*/  tree; int /*<<< orphan*/  tbl; int /*<<< orphan*/  bitlen; } ;

/* Variables and functions */
 int /*<<< orphan*/  free (int /*<<< orphan*/ ) ; 

__attribute__((used)) static void
lzh_huffman_free(struct huffman *hf)
{
	free(hf->bitlen);
	free(hf->tbl);
	free(hf->tree);
}