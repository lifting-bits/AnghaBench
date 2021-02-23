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
typedef  int /*<<< orphan*/  WCHAR ;

/* Variables and functions */
 int /*<<< orphan*/  GetProcessHeap () ; 
 int /*<<< orphan*/ * HeapAlloc (int /*<<< orphan*/ ,int /*<<< orphan*/ ,int) ; 
 int /*<<< orphan*/  lstrcpyW (int /*<<< orphan*/ *,int /*<<< orphan*/  const*) ; 
 int lstrlenW (int /*<<< orphan*/  const*) ; 

__attribute__((used)) static inline WCHAR *strdupW(const WCHAR *src)
{
    WCHAR *dest;
    if (!src) return NULL;
    dest = HeapAlloc(GetProcessHeap(), 0, (lstrlenW(src) + 1) * sizeof(WCHAR));
    if (dest) lstrcpyW(dest, src);
    return dest;
}