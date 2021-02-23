#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_5__   TYPE_1__ ;

/* Type definitions */
typedef  int uint16_t ;
struct TYPE_5__ {float fin_pad; float in_width; float in_pad; float in_height; int* in_cubemap_face_order; } ;
typedef  TYPE_1__ V360Context ;

/* Variables and functions */
 int av_clip (int /*<<< orphan*/ ,int /*<<< orphan*/ ,int const) ; 
 int ceilf (float const) ; 
 int floorf (float) ; 
 int /*<<< orphan*/  process_cube_coordinates (TYPE_1__ const*,float,float,int,float*,float*,int*) ; 
 int /*<<< orphan*/  roundf (float) ; 
 int /*<<< orphan*/  xyz_to_cube (TYPE_1__ const*,float const*,float*,float*,int*) ; 

__attribute__((used)) static void xyz_to_cube1x6(const V360Context *s,
                           const float *vec, int width, int height,
                           uint16_t us[4][4], uint16_t vs[4][4], float *du, float *dv)
{
    const float scalew = s->fin_pad > 0 ? 1.f - (float)(s->fin_pad) / s->in_width : 1.f - s->in_pad;
    const float scaleh = s->fin_pad > 0 ? 1.f - s->fin_pad / (s->in_height / 6.f) : 1.f - s->in_pad;
    const float eh = height / 6.f;
    const int ewi = width;
    float uf, vf;
    int ui, vi;
    int ehi;
    int direction, face;

    xyz_to_cube(s, vec, &uf, &vf, &direction);

    uf *= scalew;
    vf *= scaleh;

    face = s->in_cubemap_face_order[direction];
    ehi = ceilf(eh * (face + 1)) - ceilf(eh * face);

    uf = 0.5f * ewi * (uf + 1.f) - 0.5f;
    vf = 0.5f * ehi * (vf + 1.f) - 0.5f;

    ui = floorf(uf);
    vi = floorf(vf);

    *du = uf - ui;
    *dv = vf - vi;

    for (int i = -1; i < 3; i++) {
        for (int j = -1; j < 3; j++) {
            int new_ui = ui + j;
            int new_vi = vi + i;
            int v_shift;
            int new_ehi;

            if (new_ui >= 0 && new_ui < ewi && new_vi >= 0 && new_vi < ehi) {
                face = s->in_cubemap_face_order[direction];

                v_shift = ceilf(eh * face);
            } else {
                uf = 2.f * new_ui / ewi - 1.f;
                vf = 2.f * new_vi / ehi - 1.f;

                uf /= scalew;
                vf /= scaleh;

                process_cube_coordinates(s, uf, vf, direction, &uf, &vf, &face);

                uf *= scalew;
                vf *= scaleh;

                v_shift = ceilf(eh * face);
                new_ehi = ceilf(eh * (face + 1)) - v_shift;

                new_ui = av_clip(roundf(0.5f *     ewi * (uf + 1.f)), 0,     ewi - 1);
                new_vi = av_clip(roundf(0.5f * new_ehi * (vf + 1.f)), 0, new_ehi - 1);
            }

            us[i + 1][j + 1] =           new_ui;
            vs[i + 1][j + 1] = v_shift + new_vi;
        }
    }
}