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
typedef  int /*<<< orphan*/  result_t ;
typedef  int /*<<< orphan*/  method_state_t ;
typedef  int /*<<< orphan*/  config_t ;

/* Variables and functions */
 int /*<<< orphan*/  old_streaming_compress_internal (int /*<<< orphan*/ *,int /*<<< orphan*/  const*,int,int) ; 

__attribute__((used)) static result_t old_streaming_compress_cdict_advanced(
    method_state_t* base,
    config_t const* config)
{
    return old_streaming_compress_internal(
        base, config, /* advanced */ 1, /* cdict */ 1);
}