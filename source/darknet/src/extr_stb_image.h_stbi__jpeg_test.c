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
struct TYPE_5__ {int /*<<< orphan*/ * s; } ;
typedef  TYPE_1__ stbi__jpeg ;
typedef  int /*<<< orphan*/  stbi__context ;

/* Variables and functions */
 int /*<<< orphan*/  STBI_FREE (TYPE_1__*) ; 
 int /*<<< orphan*/  STBI__SCAN_type ; 
 int stbi__decode_jpeg_header (TYPE_1__*,int /*<<< orphan*/ ) ; 
 scalar_t__ stbi__malloc (int) ; 
 int /*<<< orphan*/  stbi__rewind (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  stbi__setup_jpeg (TYPE_1__*) ; 

__attribute__((used)) static int stbi__jpeg_test(stbi__context *s)
{
   int r;
   stbi__jpeg* j = (stbi__jpeg*)stbi__malloc(sizeof(stbi__jpeg));
   j->s = s;
   stbi__setup_jpeg(j);
   r = stbi__decode_jpeg_header(j, STBI__SCAN_type);
   stbi__rewind(s);
   STBI_FREE(j);
   return r;
}