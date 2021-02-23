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
struct PcapFile {scalar_t__ fp; } ;

/* Variables and functions */
 int /*<<< orphan*/  fclose (scalar_t__) ; 
 int /*<<< orphan*/  free (struct PcapFile*) ; 

void pcapfile_close(struct PcapFile *handle)
{
    if (handle == NULL)
        return;
    if (handle->fp)
        fclose(handle->fp);
    free(handle);
}