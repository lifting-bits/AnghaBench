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
typedef  void* uint_fast32_t ;
struct TYPE_2__ {float numerator; scalar_t__ denominator; } ;
struct v4l2_frmivalenum {int type; scalar_t__ index; TYPE_1__ discrete; void* height; void* width; void* pixel_format; } ;
struct dstr {int /*<<< orphan*/  array; } ;
typedef  int /*<<< orphan*/  obs_property_t ;

/* Variables and functions */
 int /*<<< orphan*/  LOG_INFO ; 
#define  V4L2_FRMIVAL_TYPE_DISCRETE 128 
 int /*<<< orphan*/  VIDIOC_ENUM_FRAMEINTERVALS ; 
 int /*<<< orphan*/  blog (int /*<<< orphan*/ ,char*) ; 
 int /*<<< orphan*/  dstr_free (struct dstr*) ; 
 int /*<<< orphan*/  dstr_init (struct dstr*) ; 
 int /*<<< orphan*/  dstr_printf (struct dstr*,char*,float) ; 
 int /*<<< orphan*/  obs_module_text (char*) ; 
 int /*<<< orphan*/  obs_property_list_add_int (int /*<<< orphan*/ *,int /*<<< orphan*/ ,int const) ; 
 int /*<<< orphan*/  obs_property_list_clear (int /*<<< orphan*/ *) ; 
 int* v4l2_framerates ; 
 int /*<<< orphan*/  v4l2_ioctl (int,int /*<<< orphan*/ ,struct v4l2_frmivalenum*) ; 
 int v4l2_pack_tuple (float,scalar_t__) ; 
 int /*<<< orphan*/  v4l2_unpack_tuple (int*,int*,int const) ; 

__attribute__((used)) static void v4l2_framerate_list(int dev, uint_fast32_t pixelformat,
				uint_fast32_t width, uint_fast32_t height,
				obs_property_t *prop)
{
	struct v4l2_frmivalenum frmival;
	frmival.pixel_format = pixelformat;
	frmival.width = width;
	frmival.height = height;
	frmival.index = 0;
	struct dstr buffer;
	dstr_init(&buffer);

	obs_property_list_clear(prop);

	obs_property_list_add_int(prop, obs_module_text("LeaveUnchanged"), -1);

	v4l2_ioctl(dev, VIDIOC_ENUM_FRAMEINTERVALS, &frmival);

	switch (frmival.type) {
	case V4L2_FRMIVAL_TYPE_DISCRETE:
		while (v4l2_ioctl(dev, VIDIOC_ENUM_FRAMEINTERVALS, &frmival) ==
		       0) {
			float fps = (float)frmival.discrete.denominator /
				    frmival.discrete.numerator;
			int pack =
				v4l2_pack_tuple(frmival.discrete.numerator,
						frmival.discrete.denominator);
			dstr_printf(&buffer, "%.2f", fps);
			obs_property_list_add_int(prop, buffer.array, pack);
			frmival.index++;
		}
		break;
	default:
		blog(LOG_INFO, "Stepwise and Continuous framerates "
			       "are currently hardcoded");

		for (const int *packed = v4l2_framerates; *packed; ++packed) {
			int num;
			int denom;
			v4l2_unpack_tuple(&num, &denom, *packed);
			float fps = (float)denom / num;
			dstr_printf(&buffer, "%.2f", fps);
			obs_property_list_add_int(prop, buffer.array, *packed);
		}
		break;
	}

	dstr_free(&buffer);
}