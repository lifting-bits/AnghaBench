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
typedef  int /*<<< orphan*/  jv ;
typedef  int /*<<< orphan*/  jq_state ;

/* Variables and functions */
 int /*<<< orphan*/  jv_free (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  jv_get_kind (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  jv_kind_name (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  jv_string (int /*<<< orphan*/ ) ; 

__attribute__((used)) static jv f_type(jq_state *jq, jv input) {
  jv out = jv_string(jv_kind_name(jv_get_kind(input)));
  jv_free(input);
  return out;
}