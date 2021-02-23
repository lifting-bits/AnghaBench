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
typedef  int /*<<< orphan*/  qhandle_t ;
typedef  int /*<<< orphan*/  iconName ;

/* Variables and functions */
 int MAX_QPATH ; 
 int /*<<< orphan*/  PlayerIcon (char const*,char*,int) ; 
 int /*<<< orphan*/  trap_R_RegisterShaderNoMip (char*) ; 

__attribute__((used)) static qhandle_t PlayerIconHandle( const char *modelAndSkin ) {
	char	iconName[MAX_QPATH];

	PlayerIcon( modelAndSkin, iconName, sizeof(iconName) );
	return trap_R_RegisterShaderNoMip( iconName );
}