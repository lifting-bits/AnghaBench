#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_9__   TYPE_1__ ;

/* Type definitions */
struct TYPE_9__ {int /*<<< orphan*/  length; struct TYPE_9__* coeff; } ;
typedef  TYPE_1__ SwsVector ;

/* Variables and functions */
 int /*<<< orphan*/  av_free (TYPE_1__*) ; 
 int /*<<< orphan*/  makenan_vec (TYPE_1__*) ; 
 TYPE_1__* sws_sumVec (TYPE_1__*,TYPE_1__*) ; 

void sws_addVec(SwsVector *a, SwsVector *b)
{
    SwsVector *sum = sws_sumVec(a, b);
    if (!sum) {
        makenan_vec(a);
        return;
    }
    av_free(a->coeff);
    a->coeff  = sum->coeff;
    a->length = sum->length;
    av_free(sum);
}