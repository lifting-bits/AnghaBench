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
struct TYPE_3__ {float* x; float* y; } ;
typedef  TYPE_1__ float_pair ;

/* Variables and functions */
 float* calloc (int,int) ; 
 int /*<<< orphan*/  error (char*) ; 

float_pair get_rnn_data(unsigned char *text, size_t *offsets, int characters, size_t len, int batch, int steps)
{
    float *x = calloc(batch * steps * characters, sizeof(float));
    float *y = calloc(batch * steps * characters, sizeof(float));
    int i,j;
    for(i = 0; i < batch; ++i){
        for(j = 0; j < steps; ++j){
            unsigned char curr = text[(offsets[i])%len];
            unsigned char next = text[(offsets[i] + 1)%len];

            x[(j*batch + i)*characters + curr] = 1;
            y[(j*batch + i)*characters + next] = 1;

            offsets[i] = (offsets[i] + 1) % len;

            if(curr > 255 || curr <= 0 || next > 255 || next <= 0){
                /*text[(index+j+2)%len] = 0;
                printf("%ld %d %d %d %d\n", index, j, len, (int)text[index+j], (int)text[index+j+1]);
                printf("%s", text+index);
                */
                error("Bad char");
            }
        }
    }
    float_pair p;
    p.x = x;
    p.y = y;
    return p;
}