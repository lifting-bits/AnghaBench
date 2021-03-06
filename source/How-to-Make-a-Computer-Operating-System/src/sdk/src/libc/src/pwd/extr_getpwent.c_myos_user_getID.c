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
typedef  int /*<<< orphan*/  uint32_t ;
typedef  int /*<<< orphan*/  passwd_myos ;

/* Variables and functions */
 int /*<<< orphan*/  myos_pass ; 
 int syscall2 (int,int,int /*<<< orphan*/ ) ; 

passwd_myos* myos_user_getID(int id){
	int ret=syscall2(69,id,(uint32_t)&myos_pass);
	if (ret!=0)
		return &myos_pass;
	else
		return NULL;
}