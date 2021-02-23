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
typedef  int /*<<< orphan*/  buffer ;
typedef  int /*<<< orphan*/  FILE ;

/* Variables and functions */
 int /*<<< orphan*/  fail (char*) ; 
 int /*<<< orphan*/  fclose (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/ * fopen (char*,char*) ; 
 scalar_t__ fprintf (int /*<<< orphan*/ *,char*,char const*) ; 
 size_t fread (char*,int,int,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  pass () ; 
 int /*<<< orphan*/  rewind (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  skip (int) ; 
 scalar_t__ strcmp (char*,char const*) ; 
 size_t strlen (char const*) ; 

__attribute__((used)) static void
fprintf__simple_string(void)
{
	FILE *file;
	char buffer[128];
	size_t length;
	const char *contents = "This is a message\n";

	file = fopen("test.txt", "w+");
	if (fprintf(file, "%s", contents) <= 0) {
		fail("fprintf failed to write to file");
		skip(2);
		return;
	}
	pass();
	rewind(file);
	length = fread(buffer, 1, sizeof(buffer) - 1, file);
	if (length != strlen(contents)) {
		fail("fread failed");
		skip(1);
		return;
	}
	pass();
	buffer[length] = '\0';
	fclose(file);

	if (strcmp(buffer, contents) != 0)
		fail("Written and read data differ");
	else
		pass();

	/* Of special note here is that we are NOT deleting the temporary
	 * files we created in this test.  Kyua takes care of this cleanup
	 * automatically and tests can (and should) rely on this behavior. */
}