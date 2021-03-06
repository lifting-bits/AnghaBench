#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_14__   TYPE_7__ ;
typedef  struct TYPE_13__   TYPE_6__ ;
typedef  struct TYPE_12__   TYPE_5__ ;
typedef  struct TYPE_11__   TYPE_4__ ;
typedef  struct TYPE_10__   TYPE_3__ ;
typedef  struct TYPE_9__   TYPE_2__ ;
typedef  struct TYPE_8__   TYPE_1__ ;

/* Type definitions */
typedef  int /*<<< orphan*/  zdev_t ;
typedef  int /*<<< orphan*/  zbuf_t ;
typedef  int u8_t ;
typedef  int u16_t ;
struct TYPE_11__ {int Length; int ElementID; } ;
struct TYPE_12__ {int* Byte; TYPE_4__ Data; } ;
struct TYPE_13__ {TYPE_5__ ExtHTCap; } ;
struct TYPE_8__ {int Length; int ElementID; } ;
struct TYPE_9__ {int* Byte; TYPE_1__ Data; } ;
struct TYPE_10__ {TYPE_2__ ExtHTCap; } ;
struct TYPE_14__ {scalar_t__ wlanMode; TYPE_6__ sta; TYPE_3__ ap; } ;

/* Variables and functions */
 scalar_t__ ZM_MODE_AP ; 
 int ZM_WLAN_EID_WPA_IE ; 
 TYPE_7__* wd ; 
 int /*<<< orphan*/  zmw_buf_writeb (int /*<<< orphan*/ *,int /*<<< orphan*/ *,int /*<<< orphan*/ ,int) ; 
 int /*<<< orphan*/  zmw_get_wlan_dev (int /*<<< orphan*/ *) ; 

u16_t zfMmAddExtendedHTCapability(zdev_t* dev, zbuf_t* buf, u16_t offset)
{
    u8_t OUI[3] = {0x0,0x90,0x4C};
    u16_t i;

    zmw_get_wlan_dev(dev);

    /* Prob ID */
    zmw_buf_writeb(dev, buf, offset++, ZM_WLAN_EID_WPA_IE);

    if ( wd->wlanMode == ZM_MODE_AP )
    {
        /* Element Length */
        zmw_buf_writeb(dev, buf, offset++, wd->ap.ExtHTCap.Data.Length + 4);

        /* OUI Data */
        for (i = 0; i < 3; i++)
        {
            zmw_buf_writeb(dev, buf, offset++, OUI[i]);
        }

        /* Element Type ID */
        zmw_buf_writeb(dev, buf, offset++, wd->ap.ExtHTCap.Data.ElementID);

        /* HT Capability Data */
        for (i = 0; i < 22; i++)
        {
            zmw_buf_writeb(dev, buf, offset++, wd->ap.ExtHTCap.Byte[i+2]);
        }
    }
    else
    {
        /* Element Length */
        zmw_buf_writeb(dev, buf, offset++, wd->sta.ExtHTCap.Data.Length + 4);

        /* OUI Data */
        for (i = 0; i < 3; i++)
        {
            zmw_buf_writeb(dev, buf, offset++, OUI[i]);
        }

        /* Element Type ID */
        zmw_buf_writeb(dev, buf, offset++, wd->sta.ExtHTCap.Data.ElementID);

        /* HT Capability Data */
        for (i = 0; i < 22; i++)
        {
            zmw_buf_writeb(dev, buf, offset++, wd->sta.ExtHTCap.Byte[i+2]);
        }
    }

    return offset;
}