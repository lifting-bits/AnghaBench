#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_3__   TYPE_1__ ;

/* Type definitions */
struct TYPE_3__ {int numOfChildren; int /*<<< orphan*/ * Children; scalar_t__ szKey; } ;
typedef  TYPE_1__ StringTable ;
typedef  int /*<<< orphan*/  Sdb ;

/* Variables and functions */
 int /*<<< orphan*/  EIGHT_HEX_DIG_UTF_16_LEN ; 
 int /*<<< orphan*/  Pe_r_bin_store_string (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  free (char*) ; 
 char* sdb_encode (unsigned char*,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  sdb_free (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/ * sdb_new0 () ; 
 int /*<<< orphan*/  sdb_ns_set (int /*<<< orphan*/ *,char*,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  sdb_set (int /*<<< orphan*/ *,char*,char*,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  snprintf (char*,int,char*,int) ; 

__attribute__((used)) static Sdb* Pe_r_bin_store_string_table(StringTable* stringTable) {
	char key[20];
	char* encodedKey = NULL;
	int i = 0;
	Sdb* sdb = NULL;
	if (!stringTable) {
		return NULL;
	}
	sdb = sdb_new0 ();
	if (!sdb) {
		return NULL;
	}
	encodedKey = sdb_encode ((unsigned char*) stringTable->szKey, EIGHT_HEX_DIG_UTF_16_LEN);
	if (!encodedKey) {
		sdb_free (sdb);
		return NULL;
	}
	sdb_set (sdb, "key", encodedKey, 0);
	free (encodedKey);
	for (; i < stringTable->numOfChildren; i++) {
		snprintf (key, 20, "string%d", i);
		sdb_ns_set (sdb, key, Pe_r_bin_store_string (stringTable->Children[i]));
	}
	return sdb;
}