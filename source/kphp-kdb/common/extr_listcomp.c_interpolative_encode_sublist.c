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
struct list_encoder {int /*<<< orphan*/  L; int /*<<< orphan*/  bw; } ;

/* Variables and functions */
 int /*<<< orphan*/  bwrite_interpolative_sublist (int /*<<< orphan*/ *,int /*<<< orphan*/ ,int,int) ; 

__attribute__((used)) static void interpolative_encode_sublist (struct list_encoder *enc, int u, int v) {
  bwrite_interpolative_sublist (&enc->bw, enc->L, u, v);
}