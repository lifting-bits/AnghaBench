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
typedef  scalar_t__ u16 ;

/* Variables and functions */
 scalar_t__ TLAN_DIO_ADR ; 
 scalar_t__ TLAN_DIO_DATA ; 
 scalar_t__ TLAN_NET_SIO ; 
 int /*<<< orphan*/  TLAN_NET_SIO_ECLOK ; 
 int /*<<< orphan*/  TLAN_NET_SIO_EDATA ; 
 int /*<<< orphan*/  TLAN_NET_SIO_ETXEN ; 
 int /*<<< orphan*/  TLan_ClearBit (int /*<<< orphan*/ ,scalar_t__) ; 
 int /*<<< orphan*/  TLan_SetBit (int /*<<< orphan*/ ,scalar_t__) ; 
 int /*<<< orphan*/  outw (scalar_t__,scalar_t__) ; 

__attribute__((used)) static void TLan_EeSendStart( u16 io_base )
{
	u16	sio;

	outw( TLAN_NET_SIO, io_base + TLAN_DIO_ADR );
	sio = io_base + TLAN_DIO_DATA + TLAN_NET_SIO;

	TLan_SetBit( TLAN_NET_SIO_ECLOK, sio );
	TLan_SetBit( TLAN_NET_SIO_EDATA, sio );
	TLan_SetBit( TLAN_NET_SIO_ETXEN, sio );
	TLan_ClearBit( TLAN_NET_SIO_EDATA, sio );
	TLan_ClearBit( TLAN_NET_SIO_ECLOK, sio );

}