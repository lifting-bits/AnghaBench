#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_2__   TYPE_1__ ;

/* Type definitions */
typedef  int /*<<< orphan*/  ut64 ;
struct TYPE_2__ {int /*<<< orphan*/  arm9_ram_address; } ;
typedef  int /*<<< orphan*/  RBinFile ;

/* Variables and functions */
 TYPE_1__ loaded_header ; 

__attribute__((used)) static ut64 baddr(RBinFile *bf) {
	return (ut64) loaded_header.arm9_ram_address;
}