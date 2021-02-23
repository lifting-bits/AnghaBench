#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_8__   TYPE_2__ ;
typedef  struct TYPE_7__   TYPE_1__ ;

/* Type definitions */
struct TYPE_7__ {float x; float y; float z; float u; float v; } ;
typedef  TYPE_1__ vita2d_texture_vertex ;
struct TYPE_8__ {int /*<<< orphan*/  gxm_tex; } ;
typedef  TYPE_2__ vita2d_texture ;

/* Variables and functions */
 int /*<<< orphan*/  SCE_GXM_INDEX_FORMAT_U16 ; 
 int /*<<< orphan*/  SCE_GXM_PRIMITIVE_TRIANGLE_STRIP ; 
 int /*<<< orphan*/  _vita2d_context ; 
 float cosf (float) ; 
 int /*<<< orphan*/  sceGxmDraw (int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int) ; 
 int /*<<< orphan*/  sceGxmSetFragmentTexture (int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  sceGxmSetVertexStream (int /*<<< orphan*/ ,int /*<<< orphan*/ ,TYPE_1__*) ; 
 float sinf (float) ; 
 int /*<<< orphan*/  vita2d_get_linear_indices () ; 
 scalar_t__ vita2d_pool_memalign (int,int) ; 
 float vita2d_texture_get_height (TYPE_2__ const*) ; 
 float vita2d_texture_get_width (TYPE_2__ const*) ; 

__attribute__((used)) static inline void draw_texture_part_scale_rotate_generic(const vita2d_texture *texture, float x, float y,
	float tex_x, float tex_y, float tex_w, float tex_h, float x_scale, float y_scale, float rad)
{
	vita2d_texture_vertex *vertices = (vita2d_texture_vertex *)vita2d_pool_memalign(
		4 * sizeof(vita2d_texture_vertex), // 4 vertices
		sizeof(vita2d_texture_vertex));

	const float w_full = vita2d_texture_get_width(texture);
	const float h_full = vita2d_texture_get_height(texture);

	const float w_half = (tex_w * x_scale) / 2.0f;
	const float h_half = (tex_h * y_scale) / 2.0f;

	const float u0 = tex_x / w_full;
	const float v0 = tex_y / h_full;
	const float u1 = (tex_x + tex_w) / w_full;
	const float v1 = (tex_y + tex_h) / h_full;

	vertices[0].x = -w_half;
	vertices[0].y = -h_half;
	vertices[0].z = +0.5f;
	vertices[0].u = u0;
	vertices[0].v = v0;

	vertices[1].x = w_half;
	vertices[1].y = -h_half;
	vertices[1].z = +0.5f;
	vertices[1].u = u1;
	vertices[1].v = v0;

	vertices[2].x = -w_half;
	vertices[2].y = h_half;
	vertices[2].z = +0.5f;
	vertices[2].u = u0;
	vertices[2].v = v1;

	vertices[3].x = w_half;
	vertices[3].y = h_half;
	vertices[3].z = +0.5f;
	vertices[3].u = u1;
	vertices[3].v = v1;

	const float c = cosf(rad);
	const float s = sinf(rad);
	int i;
	for (i = 0; i < 4; ++i) { // Rotate and translate
		float _x = vertices[i].x;
		float _y = vertices[i].y;
		vertices[i].x = _x*c - _y*s + x;
		vertices[i].y = _x*s + _y*c + y;
	}

	// Set the texture to the TEXUNIT0
	sceGxmSetFragmentTexture(_vita2d_context, 0, &texture->gxm_tex);

	sceGxmSetVertexStream(_vita2d_context, 0, vertices);
	sceGxmDraw(_vita2d_context, SCE_GXM_PRIMITIVE_TRIANGLE_STRIP, SCE_GXM_INDEX_FORMAT_U16, vita2d_get_linear_indices(), 4);
}