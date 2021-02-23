#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_7__   TYPE_1__ ;

/* Type definitions */
typedef  int /*<<< orphan*/  U8 ;
typedef  int U32 ;
struct TYPE_7__ {int /*<<< orphan*/  type; } ;
typedef  TYPE_1__ SATI_TRANSLATOR_SEQUENCE_T ;
typedef  scalar_t__ SATI_STATUS ;

/* Variables and functions */
 scalar_t__ SATI_FAILURE_CHECK_RESPONSE_DATA ; 
 int /*<<< orphan*/  SATI_SEQUENCE_VERIFY_12 ; 
 scalar_t__ SATI_SUCCESS ; 
 int /*<<< orphan*/ * sati_cb_get_cdb_address (void*) ; 
 scalar_t__ sati_device_state_stopped (TYPE_1__*,void*) ; 
 int sati_get_cdb_byte (int /*<<< orphan*/ *,int) ; 
 scalar_t__ sati_move_set_sector_count (TYPE_1__*,void*,void*,int,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  sati_move_translate_32_bit_lba (TYPE_1__*,void*,void*) ; 
 scalar_t__ sati_verify_translate_command (TYPE_1__*,void*,void*) ; 

SATI_STATUS sati_verify_12_translate_command(
   SATI_TRANSLATOR_SEQUENCE_T * sequence,
   void                       * scsi_io,
   void                       * ata_io
)
{
   SATI_STATUS   status;
   U8          * cdb          = sati_cb_get_cdb_address(scsi_io);
   U32           sector_count = (sati_get_cdb_byte(cdb, 6) << 24) |
                                (sati_get_cdb_byte(cdb, 7) << 16) |
                                (sati_get_cdb_byte(cdb, 8) << 8)  |
                                (sati_get_cdb_byte(cdb, 9));

   if(sati_device_state_stopped(sequence, scsi_io))
   {
      return SATI_FAILURE_CHECK_RESPONSE_DATA;
   }
   else
   {
      sequence->type = SATI_SEQUENCE_VERIFY_12;

      // Fill in the Logical Block Address fields and sector count registers.
      sati_move_translate_32_bit_lba(sequence, scsi_io, ata_io);
      status = sati_move_set_sector_count(sequence,scsi_io,ata_io,sector_count,0);
      if (status != SATI_SUCCESS)
         return status;

      return sati_verify_translate_command(sequence, scsi_io, ata_io);
   }
}