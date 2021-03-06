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
struct TYPE_3__ {int first_nonopt; int last_nonopt; int ind; } ;
typedef  TYPE_1__ vlc_getopt_t ;

/* Variables and functions */

__attribute__((used)) static void exchange(char **argv, vlc_getopt_t *restrict state)
{
    int bottom = state->first_nonopt;
    int middle = state->last_nonopt;
    int top = state->ind;
    char *tem;

    /* Exchange the shorter segment with the far end of the longer segment.
       That puts the shorter segment into the right place.
       It leaves the longer segment in the right place overall,
       but it consists of two parts that need to be swapped next.  */

    while (top > middle && middle > bottom)
    {
        if (top - middle > middle - bottom)
        {
            /* Bottom segment is the short one.  */
            int len = middle - bottom;
            register int i;

            /* Swap it with the top part of the top segment.  */
            for (i = 0; i < len; i++)
            {
                tem = argv[bottom + i];
                argv[bottom + i] = argv[top - (middle - bottom) + i];
                argv[top - (middle - bottom) + i] = tem;
            }
            /* Exclude the moved bottom segment from further swapping.  */
            top -= len;
        }
        else
        {
            /* Top segment is the short one.  */
            int len = top - middle;
            register int i;

            /* Swap it with the bottom part of the bottom segment.  */
            for (i = 0; i < len; i++)
            {
                tem = argv[bottom + i];
                argv[bottom + i] = argv[middle + i];
                argv[middle + i] = tem;
            }
            /* Exclude the moved top segment from further swapping.  */
            bottom += len;
        }
    }

    /* Update records for the slots the non-options now occupy.  */

    state->first_nonopt += (state->ind - state->last_nonopt);
    state->last_nonopt = state->ind;
}