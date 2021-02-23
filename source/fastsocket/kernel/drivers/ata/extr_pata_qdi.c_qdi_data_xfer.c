#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_4__   TYPE_2__ ;
typedef  struct TYPE_3__   TYPE_1__ ;

/* Type definitions */
struct TYPE_4__ {int /*<<< orphan*/  data_addr; } ;
struct ata_port {TYPE_2__ ioaddr; } ;
struct ata_device {TYPE_1__* link; int /*<<< orphan*/  id; } ;
typedef  unsigned char __le32 ;
struct TYPE_3__ {struct ata_port* ap; } ;

/* Variables and functions */
 int READ ; 
 scalar_t__ ata_id_has_dword_io (int /*<<< orphan*/ ) ; 
 unsigned int ata_sff_data_xfer (struct ata_device*,unsigned char*,unsigned int,int) ; 
 unsigned char cpu_to_le32 (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  ioread32 (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  ioread32_rep (int /*<<< orphan*/ ,unsigned char*,unsigned int) ; 
 int /*<<< orphan*/  iowrite32 (int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  iowrite32_rep (int /*<<< orphan*/ ,unsigned char*,unsigned int) ; 
 int /*<<< orphan*/  le32_to_cpu (unsigned char) ; 
 int /*<<< orphan*/  memcpy (unsigned char*,unsigned char*,int) ; 
 scalar_t__ unlikely (int) ; 

__attribute__((used)) static unsigned int qdi_data_xfer(struct ata_device *dev, unsigned char *buf,
				  unsigned int buflen, int rw)
{
	if (ata_id_has_dword_io(dev->id)) {
		struct ata_port *ap = dev->link->ap;
		int slop = buflen & 3;

		if (rw == READ)
			ioread32_rep(ap->ioaddr.data_addr, buf, buflen >> 2);
		else
			iowrite32_rep(ap->ioaddr.data_addr, buf, buflen >> 2);

		if (unlikely(slop)) {
			__le32 pad;
			if (rw == READ) {
				pad = cpu_to_le32(ioread32(ap->ioaddr.data_addr));
				memcpy(buf + buflen - slop, &pad, slop);
			} else {
				memcpy(&pad, buf + buflen - slop, slop);
				iowrite32(le32_to_cpu(pad), ap->ioaddr.data_addr);
			}
			buflen += 4 - slop;
		}
	} else
		buflen = ata_sff_data_xfer(dev, buf, buflen, rw);

	return buflen;
}