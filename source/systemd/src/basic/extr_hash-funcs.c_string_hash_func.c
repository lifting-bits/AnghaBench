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
struct siphash {int dummy; } ;

/* Variables and functions */
 int /*<<< orphan*/  siphash24_compress (char const*,scalar_t__,struct siphash*) ; 
 scalar_t__ strlen (char const*) ; 

void string_hash_func(const char *p, struct siphash *state) {
        siphash24_compress(p, strlen(p) + 1, state);
}