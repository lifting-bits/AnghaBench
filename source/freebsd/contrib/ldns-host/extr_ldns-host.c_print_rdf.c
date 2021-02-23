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
typedef  int /*<<< orphan*/  ldns_rdf ;

/* Variables and functions */
 int /*<<< orphan*/  free (char*) ; 
 char* ldns_rdf2str (int /*<<< orphan*/ *) ; 
 int printf (char*,char*) ; 

__attribute__((used)) static int
print_rdf(ldns_rdf *rdf) {
    char *str;
    int n;

    str = ldns_rdf2str(rdf);
    n = printf("%s", str);
    free(str);
    return n;
}