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
typedef  int /*<<< orphan*/  aucRef ;
typedef  int /*<<< orphan*/  aucMagic ;
typedef  int /*<<< orphan*/  FILE ;

/* Variables and functions */
 int /*<<< orphan*/  contains_data (int /*<<< orphan*/ *,int,unsigned char*,int) ; 

int is_fat_32_br(FILE *fp)
{
   /* A "file" is probably some kind of FAT32 boot record if it contains the
      magic chars 0x55, 0xAA at positions 0x1FE, 0x3FE and 0x5FE */
   unsigned char aucRef[] = {0x55, 0xAA};
   unsigned char aucMagic[] = {'M','S','W','I','N','4','.','1'};
   int i;

   for(i=0 ; i<3 ; i++)
      if( ! contains_data(fp, 0x1FE + i*0x200, aucRef, sizeof(aucRef)))
	 return 0;
   if( ! contains_data(fp, 0x03, aucMagic, sizeof(aucMagic)))
      return 0;
   return 1;
}