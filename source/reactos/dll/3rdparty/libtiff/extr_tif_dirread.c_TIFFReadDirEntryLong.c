#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_11__   TYPE_1__ ;

/* Type definitions */
typedef  int /*<<< orphan*/  uint8 ;
typedef  int /*<<< orphan*/  uint64 ;
typedef  int /*<<< orphan*/  uint32 ;
typedef  int /*<<< orphan*/  uint16 ;
typedef  int /*<<< orphan*/  int8 ;
typedef  int /*<<< orphan*/  int64 ;
typedef  int /*<<< orphan*/  int32 ;
typedef  int /*<<< orphan*/  int16 ;
typedef  enum TIFFReadDirEntryErr { ____Placeholder_TIFFReadDirEntryErr } TIFFReadDirEntryErr ;
struct TYPE_11__ {int tdir_count; int tdir_type; } ;
typedef  TYPE_1__ TIFFDirEntry ;
typedef  int /*<<< orphan*/  TIFF ;

/* Variables and functions */
 int TIFFReadDirEntryCheckRangeLongLong8 (int /*<<< orphan*/ ) ; 
 int TIFFReadDirEntryCheckRangeLongSbyte (int /*<<< orphan*/ ) ; 
 int TIFFReadDirEntryCheckRangeLongSlong (int /*<<< orphan*/ ) ; 
 int TIFFReadDirEntryCheckRangeLongSlong8 (int /*<<< orphan*/ ) ; 
 int TIFFReadDirEntryCheckRangeLongSshort (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  TIFFReadDirEntryCheckedByte (int /*<<< orphan*/ *,TYPE_1__*,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  TIFFReadDirEntryCheckedLong (int /*<<< orphan*/ *,TYPE_1__*,int /*<<< orphan*/ *) ; 
 int TIFFReadDirEntryCheckedLong8 (int /*<<< orphan*/ *,TYPE_1__*,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  TIFFReadDirEntryCheckedSbyte (int /*<<< orphan*/ *,TYPE_1__*,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  TIFFReadDirEntryCheckedShort (int /*<<< orphan*/ *,TYPE_1__*,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  TIFFReadDirEntryCheckedSlong (int /*<<< orphan*/ *,TYPE_1__*,int /*<<< orphan*/ *) ; 
 int TIFFReadDirEntryCheckedSlong8 (int /*<<< orphan*/ *,TYPE_1__*,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  TIFFReadDirEntryCheckedSshort (int /*<<< orphan*/ *,TYPE_1__*,int /*<<< orphan*/ *) ; 
 int TIFFReadDirEntryErrCount ; 
 int TIFFReadDirEntryErrOk ; 
 int TIFFReadDirEntryErrType ; 
#define  TIFF_BYTE 135 
#define  TIFF_LONG 134 
#define  TIFF_LONG8 133 
#define  TIFF_SBYTE 132 
#define  TIFF_SHORT 131 
#define  TIFF_SLONG 130 
#define  TIFF_SLONG8 129 
#define  TIFF_SSHORT 128 

__attribute__((used)) static enum TIFFReadDirEntryErr TIFFReadDirEntryLong(TIFF* tif, TIFFDirEntry* direntry, uint32* value)
{
	enum TIFFReadDirEntryErr err;
	if (direntry->tdir_count!=1)
		return(TIFFReadDirEntryErrCount);
	switch (direntry->tdir_type)
	{
		case TIFF_BYTE:
			{
				uint8 m;
				TIFFReadDirEntryCheckedByte(tif,direntry,&m);
				*value=(uint32)m;
				return(TIFFReadDirEntryErrOk);
			}
		case TIFF_SBYTE:
			{
				int8 m;
				TIFFReadDirEntryCheckedSbyte(tif,direntry,&m);
				err=TIFFReadDirEntryCheckRangeLongSbyte(m);
				if (err!=TIFFReadDirEntryErrOk)
					return(err);
				*value=(uint32)m;
				return(TIFFReadDirEntryErrOk);
			}
		case TIFF_SHORT:
			{
				uint16 m;
				TIFFReadDirEntryCheckedShort(tif,direntry,&m);
				*value=(uint32)m;
				return(TIFFReadDirEntryErrOk);
			}
		case TIFF_SSHORT:
			{
				int16 m;
				TIFFReadDirEntryCheckedSshort(tif,direntry,&m);
				err=TIFFReadDirEntryCheckRangeLongSshort(m);
				if (err!=TIFFReadDirEntryErrOk)
					return(err);
				*value=(uint32)m;
				return(TIFFReadDirEntryErrOk);
			}
		case TIFF_LONG:
			TIFFReadDirEntryCheckedLong(tif,direntry,value);
			return(TIFFReadDirEntryErrOk);
		case TIFF_SLONG:
			{
				int32 m;
				TIFFReadDirEntryCheckedSlong(tif,direntry,&m);
				err=TIFFReadDirEntryCheckRangeLongSlong(m);
				if (err!=TIFFReadDirEntryErrOk)
					return(err);
				*value=(uint32)m;
				return(TIFFReadDirEntryErrOk);
			}
		case TIFF_LONG8:
			{
				uint64 m;
				err=TIFFReadDirEntryCheckedLong8(tif,direntry,&m);
				if (err!=TIFFReadDirEntryErrOk)
					return(err);
				err=TIFFReadDirEntryCheckRangeLongLong8(m);
				if (err!=TIFFReadDirEntryErrOk)
					return(err);
				*value=(uint32)m;
				return(TIFFReadDirEntryErrOk);
			}
		case TIFF_SLONG8:
			{
				int64 m;
				err=TIFFReadDirEntryCheckedSlong8(tif,direntry,&m);
				if (err!=TIFFReadDirEntryErrOk)
					return(err);
				err=TIFFReadDirEntryCheckRangeLongSlong8(m);
				if (err!=TIFFReadDirEntryErrOk)
					return(err);
				*value=(uint32)m;
				return(TIFFReadDirEntryErrOk);
			}
		default:
			return(TIFFReadDirEntryErrType);
	}
}