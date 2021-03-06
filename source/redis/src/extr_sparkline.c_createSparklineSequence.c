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
struct sequence {int /*<<< orphan*/ * samples; scalar_t__ length; } ;

/* Variables and functions */
 struct sequence* zmalloc (int) ; 

struct sequence *createSparklineSequence(void) {
    struct sequence *seq = zmalloc(sizeof(*seq));
    seq->length = 0;
    seq->samples = NULL;
    return seq;
}