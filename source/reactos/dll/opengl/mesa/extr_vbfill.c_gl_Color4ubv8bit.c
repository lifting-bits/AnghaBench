#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_9__   TYPE_4__ ;
typedef  struct TYPE_8__   TYPE_3__ ;
typedef  struct TYPE_7__   TYPE_2__ ;
typedef  struct TYPE_6__   TYPE_1__ ;

/* Type definitions */
struct TYPE_7__ {int /*<<< orphan*/  ColorMaterialEnabled; } ;
struct TYPE_6__ {int /*<<< orphan*/  ByteColor; } ;
struct TYPE_9__ {TYPE_3__* VB; TYPE_2__ Light; TYPE_1__ Current; } ;
struct TYPE_8__ {int /*<<< orphan*/  MonoColor; } ;
typedef  int /*<<< orphan*/  GLubyte ;
typedef  TYPE_4__ GLcontext ;

/* Variables and functions */
 int /*<<< orphan*/  ASSERT (int) ; 
 int /*<<< orphan*/  COPY_4UBV (int /*<<< orphan*/ ,int /*<<< orphan*/  const*) ; 
 int /*<<< orphan*/  GL_FALSE ; 

void gl_Color4ubv8bit( GLcontext *ctx, const GLubyte *c )
{
   COPY_4UBV( ctx->Current.ByteColor, c );
   ASSERT( !ctx->Light.ColorMaterialEnabled );
   ctx->VB->MonoColor = GL_FALSE;
}