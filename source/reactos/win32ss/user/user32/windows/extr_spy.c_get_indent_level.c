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
typedef  int /*<<< orphan*/  INT_PTR ;

/* Variables and functions */
 int /*<<< orphan*/  TlsGetValue (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  indent_tls_index ; 

__attribute__((used)) static inline INT_PTR get_indent_level(void)
{
    return (INT_PTR)TlsGetValue( indent_tls_index );
}