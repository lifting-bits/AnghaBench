#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_7__   TYPE_3__ ;
typedef  struct TYPE_6__   TYPE_2__ ;
typedef  struct TYPE_5__   TYPE_1__ ;

/* Type definitions */
typedef  scalar_t__ u_long ;
typedef  int /*<<< orphan*/  this ;
struct TYPE_6__ {int /*<<< orphan*/  sb_ccc; } ;
struct TYPE_5__ {int /*<<< orphan*/  sb_ccc; } ;
struct socket {int so_options; TYPE_2__ so_snd; TYPE_1__ so_rcv; } ;
typedef  int /*<<< orphan*/  so ;
typedef  int /*<<< orphan*/  remote ;
typedef  int /*<<< orphan*/  pcb ;
struct TYPE_7__ {int /*<<< orphan*/  state; int /*<<< orphan*/  dlci; int /*<<< orphan*/  channel; int /*<<< orphan*/  dst; int /*<<< orphan*/  src; scalar_t__ so; } ;
typedef  TYPE_3__ ng_btsocket_rfcomm_pcb_t ;
typedef  int /*<<< orphan*/ * ng_btsocket_rfcomm_pcb_p ;
typedef  int /*<<< orphan*/  local ;
typedef  int /*<<< orphan*/  kvm_t ;

/* Variables and functions */
 int /*<<< orphan*/ * LIST_NEXT (TYPE_3__*,int /*<<< orphan*/ *) ; 
 int SO_ACCEPTCONN ; 
 int /*<<< orphan*/  bdaddrpr (int /*<<< orphan*/ *,char*,int) ; 
 int /*<<< orphan*/  fprintf (int /*<<< orphan*/ ,char*,...) ; 
 scalar_t__ kread (int /*<<< orphan*/ *,scalar_t__,char*,int) ; 
 char* state2str (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  stdout ; 

__attribute__((used)) static void
rfcommpr(kvm_t *kvmd, u_long addr)
{
	static char const * const	states[] = {
	/* NG_BTSOCKET_RFCOMM_DLC_CLOSED */	   "CLOSED",
	/* NG_BTSOCKET_RFCOMM_DLC_W4_CONNECT */	   "W4CON",
	/* NG_BTSOCKET_RFCOMM_DLC_CONFIGURING */   "CONFIG",
	/* NG_BTSOCKET_RFCOMM_DLC_CONNECTING */    "CONN",
	/* NG_BTSOCKET_RFCOMM_DLC_CONNECTED */     "OPEN",
	/* NG_BTSOCKET_RFCOMM_DLC_DISCONNECTING */ "DISCON"
	};

	ng_btsocket_rfcomm_pcb_p	this = NULL, next = NULL;
	ng_btsocket_rfcomm_pcb_t	pcb;
	struct socket			so;
	int				first = 1;
	char				local[24], remote[24];

	if (addr == 0)
		return;

        if (kread(kvmd, addr, (char *) &this, sizeof(this)) < 0)
		return;

	for ( ; this != NULL; this = next) {
		if (kread(kvmd, (u_long) this, (char *) &pcb, sizeof(pcb)) < 0)
			return;
		if (kread(kvmd, (u_long) pcb.so, (char *) &so, sizeof(so)) < 0)
			return;

		next = LIST_NEXT(&pcb, next);

		if (first) {
			first = 0;
			fprintf(stdout,
"Active RFCOMM sockets\n" \
"%-8.8s %-6.6s %-6.6s %-17.17s %-17.17s %-4.4s %-4.4s %s\n",
				"PCB",
				"Recv-Q",
				"Send-Q",
				"Local address",
				"Foreign address",
				"Chan",
				"DLCI",
				"State");
		}

		fprintf(stdout,
"%-8lx %6d %6d %-17.17s %-17.17s %-4d %-4d %s\n",
			(unsigned long) this,
			so.so_rcv.sb_ccc,
			so.so_snd.sb_ccc,
			bdaddrpr(&pcb.src, local, sizeof(local)),
			bdaddrpr(&pcb.dst, remote, sizeof(remote)),
			pcb.channel,
			pcb.dlci,
			(so.so_options & SO_ACCEPTCONN)?
				"LISTEN" : state2str(pcb.state));
	}
}