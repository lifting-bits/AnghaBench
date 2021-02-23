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
typedef  int /*<<< orphan*/  PyObject ;

/* Variables and functions */
 scalar_t__ PyErr_Occurred () ; 
 int /*<<< orphan*/ * PyObject_CallMethod (void*,char*,char*,char const*,char const*) ; 
 scalar_t__ PyObject_IsTrue (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  Py_XDECREF (int /*<<< orphan*/ *) ; 

__attribute__((used)) static bool fetch_level_from_cache(void* level_cache_context,
                                   const char* const cache_paths[],
                                   int num_cache_paths,
                                   const char* key,
                                   const char* pk3_path) {
  // If an error is already pending in the runtime, we take no further action.
  if (PyErr_Occurred()) return false;

  // We ignore cache paths. They can be set in level cache Python object.
  PyObject* output = PyObject_CallMethod(
      level_cache_context, "fetch", "ss", key, pk3_path);

  bool result = output != NULL && PyObject_IsTrue(output);

  Py_XDECREF(output);

  return result;
}