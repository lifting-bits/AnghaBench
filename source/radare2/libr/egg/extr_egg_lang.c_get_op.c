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
 int is_op (char) ; 
 int /*<<< orphan*/  is_var (char*) ; 

__attribute__((used)) static inline int get_op(char **pos){
	while (**pos && !(is_op (**pos) && !is_var (*pos))) {
		(*pos)++;
	}
	return (**pos)? ((is_op (**pos)) + 1): 0;
}