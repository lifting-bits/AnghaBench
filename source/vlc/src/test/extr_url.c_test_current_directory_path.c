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

/* Variables and functions */
 int /*<<< orphan*/  abort () ; 
 int asprintf (char**,char*,char const*,char const*) ; 
 int /*<<< orphan*/  free (char*) ; 
 int /*<<< orphan*/  make_URI_def ; 
 int /*<<< orphan*/  test (int /*<<< orphan*/ ,char const*,char*) ; 

__attribute__((used)) static inline void test_current_directory_path (const char *in, const char *cwd, const char *out)
{
    char *expected_result;
    int val = asprintf (&expected_result, "file://%s/%s", cwd, out);
    if (val < 0)
        abort();

    test (make_URI_def, in, expected_result);
    free(expected_result);
}