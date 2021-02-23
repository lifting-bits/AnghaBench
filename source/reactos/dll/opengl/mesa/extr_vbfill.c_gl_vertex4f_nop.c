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
typedef  int /*<<< orphan*/  GLfloat ;
typedef  int /*<<< orphan*/  GLcontext ;

/* Variables and functions */
 int /*<<< orphan*/  GL_INVALID_OPERATION ; 
 int /*<<< orphan*/  gl_error (int /*<<< orphan*/ *,int /*<<< orphan*/ ,char*) ; 

void gl_vertex4f_nop( GLcontext *ctx,
                      GLfloat x, GLfloat y, GLfloat z, GLfloat w )
{
   gl_error( ctx, GL_INVALID_OPERATION, "glVertex4" );
}