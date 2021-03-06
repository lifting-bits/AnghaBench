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
typedef  int /*<<< orphan*/  iso639_lang_t ;

/* Variables and functions */
 int /*<<< orphan*/  const lang_any ; 
 int lang_count ; 
 int /*<<< orphan*/  const* languages ; 

const iso639_lang_t* lang_get_next(const iso639_lang_t *last)
{
    if (last == NULL || last == &lang_any)
    {
        return (const iso639_lang_t*)languages;
    }
    if (last <  languages ||                // out of bounds
        last >= languages + lang_count - 2) // last valid language
    {
        return NULL;
    }
    return ++last;
}