#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_2__   TYPE_1__ ;

/* Type definitions */
struct resampler_data {int input_frames; double ratio; int output_frames; scalar_t__ data_out; scalar_t__ data_in; } ;
struct TYPE_2__ {double distance; int /*<<< orphan*/ * buffer; } ;
typedef  TYPE_1__ rarch_CC_resampler_t ;
typedef  int /*<<< orphan*/  audio_frame_float_t ;
typedef  int /*<<< orphan*/  __m64 ;
typedef  int /*<<< orphan*/  __m128 ;

/* Variables and functions */
 int /*<<< orphan*/  _MM_SHUFFLE (int,int,int,int) ; 
 int /*<<< orphan*/  _mm_add_ps (int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  _mm_loadl_pi (int /*<<< orphan*/ ,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  _mm_loadu_ps (float*) ; 
 int /*<<< orphan*/  _mm_max_ps (int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  _mm_min_ps (int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  _mm_mul_ps (int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  _mm_set_ps (double,double,double,double) ; 
 int /*<<< orphan*/  _mm_set_ps1 (double) ; 
 int /*<<< orphan*/  _mm_setzero_ps () ; 
 int /*<<< orphan*/  _mm_shuffle_ps (int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  _mm_storel_pi (int /*<<< orphan*/ *,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  _mm_storeu_ps (float*,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  _mm_sub_ps (int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 float float_min (double,double) ; 

__attribute__((used)) static void resampler_CC_upsample(void *re_, struct resampler_data *data)
{
   rarch_CC_resampler_t *re     = (rarch_CC_resampler_t*)re_;
   audio_frame_float_t *inp     = (audio_frame_float_t*)data->data_in;
   audio_frame_float_t *inp_max = (audio_frame_float_t*)(inp + data->input_frames);
   audio_frame_float_t *outp    = (audio_frame_float_t*)data->data_out;
   float b                      = float_min(data->ratio, 1.00); /* cutoff frequency. */
   float ratio                  = 1.0 / data->ratio;
   __m128 vec_previous          = _mm_loadu_ps((float*)&re->buffer[0]);
   __m128 vec_current           = _mm_loadu_ps((float*)&re->buffer[2]);

   while (inp != inp_max)
   {
      __m128 vec_in = _mm_loadl_pi(_mm_setzero_ps(),(__m64*)inp);
      vec_previous =
         _mm_shuffle_ps(vec_previous,vec_current,_MM_SHUFFLE(1, 0, 3, 2));
      vec_current  =
         _mm_shuffle_ps(vec_current,vec_in,_MM_SHUFFLE(1, 0, 3, 2));

      while (re->distance < 1.0)
      {
         __m128 vec_w_previous, vec_w_current, vec_out;
#if (CC_RESAMPLER_PRECISION > 0)
         __m128 vec_ww1, vec_ww2;
#endif
         __m128 vec_w =
            _mm_add_ps(_mm_set_ps1(re->distance), _mm_set_ps(-2.0, -1.0, 0.0, 1.0));

         __m128 vec_w1 = _mm_add_ps(vec_w , _mm_set_ps1(0.5));
         __m128 vec_w2 = _mm_sub_ps(vec_w , _mm_set_ps1(0.5));

         __m128 vec_b = _mm_set_ps1(b);
         vec_w1 = _mm_mul_ps(vec_w1, vec_b);
         vec_w2 = _mm_mul_ps(vec_w2, vec_b);

#if (CC_RESAMPLER_PRECISION > 0)
         vec_ww1 = _mm_mul_ps(vec_w1, vec_w1);
         vec_ww2 = _mm_mul_ps(vec_w2, vec_w2);

         vec_ww1 = _mm_mul_ps(vec_ww1,_mm_sub_ps(_mm_set_ps1(3.0),vec_ww1));
         vec_ww2 = _mm_mul_ps(vec_ww2,_mm_sub_ps(_mm_set_ps1(3.0),vec_ww2));

         vec_ww1 = _mm_mul_ps(_mm_set_ps1(1.0 / 4.0), vec_ww1);
         vec_ww2 = _mm_mul_ps(_mm_set_ps1(1.0 / 4.0), vec_ww2);

         vec_w1  = _mm_mul_ps(vec_w1, _mm_sub_ps(_mm_set_ps1(1.0), vec_ww1));
         vec_w2  = _mm_mul_ps(vec_w2, _mm_sub_ps(_mm_set_ps1(1.0), vec_ww2));
#endif

         vec_w1  = _mm_min_ps(vec_w1, _mm_set_ps1( 0.5));
         vec_w2  = _mm_min_ps(vec_w2, _mm_set_ps1( 0.5));
         vec_w1  = _mm_max_ps(vec_w1, _mm_set_ps1(-0.5));
         vec_w2  = _mm_max_ps(vec_w2, _mm_set_ps1(-0.5));

         vec_w   = _mm_sub_ps(vec_w1, vec_w2);

         vec_w_previous = _mm_shuffle_ps(vec_w,vec_w,_MM_SHUFFLE(1, 1, 0, 0));
         vec_w_current  = _mm_shuffle_ps(vec_w,vec_w,_MM_SHUFFLE(3, 3, 2, 2));

         vec_out =  _mm_mul_ps(vec_previous, vec_w_previous);
         vec_out = _mm_add_ps(vec_out, _mm_mul_ps(vec_current, vec_w_current));
         vec_out =
            _mm_add_ps(vec_out, _mm_shuffle_ps(vec_out,vec_out,_MM_SHUFFLE(3, 2, 3, 2)));

         _mm_storel_pi((__m64*)outp,vec_out);

         re->distance += ratio;
         outp++;
      }

      re->distance -= 1.0;
      inp++;
   }

   _mm_storeu_ps((float*)&re->buffer[0], vec_previous);
   _mm_storeu_ps((float*)&re->buffer[2],  vec_current);

   data->output_frames = outp - (audio_frame_float_t*)data->data_out;
}