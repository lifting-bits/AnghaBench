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

/* Variables and functions */
 int /*<<< orphan*/  MSG (char*) ; 
 int /*<<< orphan*/  exit (int) ; 
 int /*<<< orphan*/  free (void* const) ; 
 size_t getFileSize (char const*) ; 
 int /*<<< orphan*/  loadFile (void* const,char const*,size_t const) ; 
 void* malloc (size_t const) ; 
 int /*<<< orphan*/  roundTripCheck (void* const,size_t const,int) ; 

__attribute__((used)) static void fileCheck(const char* fileName, int clevel)
{
    size_t const fileSize = getFileSize(fileName);
    void* const buffer = malloc(fileSize + !fileSize /* avoid 0 */);
    if (!buffer) {
        MSG("not enough memory \n");
        exit(4);
    }
    loadFile(buffer, fileName, fileSize);
    roundTripCheck(buffer, fileSize, clevel);
    free (buffer);
}