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
struct path {struct path* filter; struct path* class; } ;

/* Variables and functions */
 int /*<<< orphan*/  heap_free (struct path*) ; 

__attribute__((used)) static void free_path( struct path *path )
{
    heap_free( path->class );
    heap_free( path->filter );
    heap_free( path );
}