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
typedef  char WCHAR ;
typedef  int BOOL ;

/* Variables and functions */
 scalar_t__ is_alpha (char const) ; 
 scalar_t__ is_unc_path (char const*) ; 

__attribute__((used)) static inline BOOL is_implicit_file_path(const WCHAR *str) {
    return (is_unc_path(str) || (is_alpha(str[0]) && str[1] == ':'));
}