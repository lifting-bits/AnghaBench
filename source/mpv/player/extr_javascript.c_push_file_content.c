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
typedef  int /*<<< orphan*/  js_State ;

/* Variables and functions */
 int /*<<< orphan*/  js_throw (int /*<<< orphan*/ *) ; 
 int s_push_file (int /*<<< orphan*/ *,char const*,int,void*) ; 
 int /*<<< orphan*/  talloc_free (void*) ; 
 void* talloc_new (int /*<<< orphan*/ *) ; 

__attribute__((used)) static void push_file_content(js_State *J, const char *fname, int limit)
{
    void *af = talloc_new(NULL);
    int r = s_push_file(J, fname, limit, af);
    talloc_free(af);
    if (r)
        js_throw(J);
}