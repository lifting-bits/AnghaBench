#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_5__   TYPE_2__ ;
typedef  struct TYPE_4__   TYPE_1__ ;

/* Type definitions */
struct TYPE_5__ {int a0; int b0; } ;
struct TYPE_4__ {TYPE_2__* section; } ;
typedef  TYPE_1__ EqualizatorFilter ;

/* Variables and functions */
 double M_PI ; 
 int /*<<< orphan*/  butterworth_fo_section (TYPE_2__*,double,double,double,double,double,double) ; 
 double cos (double) ; 
 double ff_exp10 (double) ; 
 double pow (double,double) ; 
 double sin (double) ; 
 double sqrt (double) ; 
 double tan (double) ; 

__attribute__((used)) static void butterworth_bp_filter(EqualizatorFilter *f,
                                  int N, double w0, double wb,
                                  double G, double Gb, double G0)
{
    double g, c0, g0, beta;
    double epsilon;
    int r =  N % 2;
    int L = (N - r) / 2;
    int i;

    if (G == 0 && G0 == 0) {
        f->section[0].a0 = 1;
        f->section[0].b0 = 1;
        f->section[1].a0 = 1;
        f->section[1].b0 = 1;
        return;
    }

    G  = ff_exp10(G/20);
    Gb = ff_exp10(Gb/20);
    G0 = ff_exp10(G0/20);

    epsilon = sqrt((G * G - Gb * Gb) / (Gb * Gb - G0 * G0));
    g  = pow(G,  1.0 / N);
    g0 = pow(G0, 1.0 / N);
    beta = pow(epsilon, -1.0 / N) * tan(wb/2);
    c0 = cos(w0);

    for (i = 1; i <= L; i++) {
        double ui = (2.0 * i - 1) / N;
        double si = sin(M_PI * ui / 2.0);
        double Di = beta * beta + 2 * si * beta + 1;

        butterworth_fo_section(&f->section[i - 1], beta, si, g, g0, Di, c0);
    }
}