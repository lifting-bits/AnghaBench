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
 int atoi (char const*) ; 
 int /*<<< orphan*/  compressFile_orDie (char const* const,char const* const,int,unsigned int const,int const) ; 
 char* createOutFilename_orDie (char const* const) ; 
 int /*<<< orphan*/  printf (char*,...) ; 

int main(int argc, const char** argv) {
    const char* const exeName = argv[0];
    if (argc!=4) {
        printf("wrong arguments\n");
        printf("usage:\n");
        printf("%s FILE FRAME_SIZE NB_THREADS\n", exeName);
        return 1;
    }

    {   const char* const inFileName = argv[1];
        unsigned const frameSize = (unsigned)atoi(argv[2]);
        int const nbThreads = atoi(argv[3]);

        const char* const outFileName = createOutFilename_orDie(inFileName);
        compressFile_orDie(inFileName, outFileName, 5, frameSize, nbThreads);
    }

    return 0;
}