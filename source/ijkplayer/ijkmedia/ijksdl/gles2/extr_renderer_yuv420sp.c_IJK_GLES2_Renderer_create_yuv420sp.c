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
struct TYPE_5__ {int /*<<< orphan*/  func_uploadTexture; int /*<<< orphan*/  func_getBufferWidth; int /*<<< orphan*/  func_use; int /*<<< orphan*/  program; void* um3_color_conversion; void** us2_sampler; } ;
typedef  TYPE_1__ IJK_GLES2_Renderer ;

/* Variables and functions */
 TYPE_1__* IJK_GLES2_Renderer_create_base (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  IJK_GLES2_Renderer_free (TYPE_1__*) ; 
 int /*<<< orphan*/  IJK_GLES2_checkError_TRACE (char*) ; 
 int /*<<< orphan*/  IJK_GLES2_getFragmentShader_yuv420sp () ; 
 void* glGetUniformLocation (int /*<<< orphan*/ ,char*) ; 
 int /*<<< orphan*/  yuv420sp_getBufferWidth ; 
 int /*<<< orphan*/  yuv420sp_uploadTexture ; 
 int /*<<< orphan*/  yuv420sp_use ; 

IJK_GLES2_Renderer *IJK_GLES2_Renderer_create_yuv420sp()
{
    IJK_GLES2_Renderer *renderer = IJK_GLES2_Renderer_create_base(IJK_GLES2_getFragmentShader_yuv420sp());
    if (!renderer)
        goto fail;

    renderer->us2_sampler[0] = glGetUniformLocation(renderer->program, "us2_SamplerX"); IJK_GLES2_checkError_TRACE("glGetUniformLocation(us2_SamplerX)");
    renderer->us2_sampler[1] = glGetUniformLocation(renderer->program, "us2_SamplerY"); IJK_GLES2_checkError_TRACE("glGetUniformLocation(us2_SamplerY)");

    renderer->um3_color_conversion = glGetUniformLocation(renderer->program, "um3_ColorConversion"); IJK_GLES2_checkError_TRACE("glGetUniformLocation(um3_ColorConversionMatrix)");

    renderer->func_use            = yuv420sp_use;
    renderer->func_getBufferWidth = yuv420sp_getBufferWidth;
    renderer->func_uploadTexture  = yuv420sp_uploadTexture;

    return renderer;
fail:
    IJK_GLES2_Renderer_free(renderer);
    return NULL;
}