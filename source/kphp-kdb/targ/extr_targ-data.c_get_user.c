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
typedef  int /*<<< orphan*/  user_t ;

/* Variables and functions */
 int /*<<< orphan*/ ** User ; 
 int conv_user_id (int) ; 

user_t *get_user (int user_id) {
  int i = conv_user_id (user_id);
  return i >= 0 ? User[i] : 0;
}