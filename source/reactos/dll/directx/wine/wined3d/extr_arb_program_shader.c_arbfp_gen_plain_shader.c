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
struct wined3d_string_buffer {int /*<<< orphan*/  buffer; } ;
struct wined3d_gl_info {int dummy; } ;
struct arbfp_blit_type {scalar_t__ use_color_key; int /*<<< orphan*/  res_type; } ;
typedef  int /*<<< orphan*/  GLuint ;

/* Variables and functions */
 int /*<<< orphan*/  ARBFP_BLIT_PARAM_COLOR_KEY_HIGH ; 
 int /*<<< orphan*/  ARBFP_BLIT_PARAM_COLOR_KEY_LOW ; 
 int /*<<< orphan*/  ERR (char*) ; 
 int /*<<< orphan*/  GL_EXTCALL (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  GL_FRAGMENT_PROGRAM_ARB ; 
 char* arbfp_texture_target (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  glBindProgramARB (int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  glGenProgramsARB (int,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  shader_addline (struct wined3d_string_buffer*,char*,...) ; 
 int /*<<< orphan*/  shader_arb_compile (struct wined3d_gl_info const*,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  string_buffer_free (struct wined3d_string_buffer*) ; 
 int /*<<< orphan*/  string_buffer_init (struct wined3d_string_buffer*) ; 

__attribute__((used)) static GLuint arbfp_gen_plain_shader(const struct wined3d_gl_info *gl_info, const struct arbfp_blit_type *type)
{
    GLuint shader;
    struct wined3d_string_buffer buffer;
    const char *tex_target = arbfp_texture_target(type->res_type);

    /* Shader header */
    if (!string_buffer_init(&buffer))
    {
        ERR("Failed to initialize shader buffer.\n");
        return 0;
    }

    GL_EXTCALL(glGenProgramsARB(1, &shader));
    if (!shader)
    {
        string_buffer_free(&buffer);
        return 0;
    }
    GL_EXTCALL(glBindProgramARB(GL_FRAGMENT_PROGRAM_ARB, shader));

    shader_addline(&buffer, "!!ARBfp1.0\n");

    if (type->use_color_key)
    {
        shader_addline(&buffer, "TEMP color;\n");
        shader_addline(&buffer, "TEMP less, greater;\n");
        shader_addline(&buffer, "PARAM color_key_low = program.local[%u];\n", ARBFP_BLIT_PARAM_COLOR_KEY_LOW);
        shader_addline(&buffer, "PARAM color_key_high = program.local[%u];\n", ARBFP_BLIT_PARAM_COLOR_KEY_HIGH);
        shader_addline(&buffer, "TEX color, fragment.texcoord[0], texture[0], %s;\n", tex_target);
        shader_addline(&buffer, "SLT less, color, color_key_low;\n"); /* below low key */
        shader_addline(&buffer, "SGE greater, color, color_key_high;\n"); /* above high key */
        shader_addline(&buffer, "ADD less, less, greater;\n"); /* or */
        shader_addline(&buffer, "DP4 less.b, less, less;\n"); /* on any channel */
        shader_addline(&buffer, "SGE less, -less.b, 0.0;\n"); /* logical not */
        shader_addline(&buffer, "KIL -less;\n"); /* discard if true */
        shader_addline(&buffer, "MOV result.color, color;\n");
    }
    else
    {
        shader_addline(&buffer, "TEX result.color, fragment.texcoord[0], texture[0], %s;\n", tex_target);
    }

    shader_addline(&buffer, "END\n");

    shader_arb_compile(gl_info, GL_FRAGMENT_PROGRAM_ARB, buffer.buffer);

    string_buffer_free(&buffer);

    return shader;
}