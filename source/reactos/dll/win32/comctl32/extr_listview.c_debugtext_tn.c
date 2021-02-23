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
typedef  scalar_t__ LPCWSTR ;
typedef  char* LPCSTR ;
typedef  int /*<<< orphan*/  INT ;
typedef  scalar_t__ BOOL ;

/* Variables and functions */
 scalar_t__ LPSTR_TEXTCALLBACKW ; 
 char* debugstr_an (char*,int /*<<< orphan*/ ) ; 
 char* debugstr_wn (scalar_t__,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  min (int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  textlenT (scalar_t__,scalar_t__) ; 

__attribute__((used)) static inline LPCSTR debugtext_tn(LPCWSTR text, BOOL isW, INT n)
{
    if (text == LPSTR_TEXTCALLBACKW) return "(callback)";
    n = min(textlenT(text, isW), n);
    return isW ? debugstr_wn(text, n) : debugstr_an((LPCSTR)text, n);
}