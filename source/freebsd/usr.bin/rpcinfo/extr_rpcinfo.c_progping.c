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
typedef  int /*<<< orphan*/  xdrproc_t ;
typedef  scalar_t__ u_long ;
struct timeval {int tv_sec; scalar_t__ tv_usec; } ;
struct TYPE_2__ {scalar_t__ low; scalar_t__ high; } ;
struct rpc_err {TYPE_1__ re_vers; } ;
struct netconfig {int dummy; } ;
typedef  enum clnt_stat { ____Placeholder_clnt_stat } clnt_stat ;
typedef  int /*<<< orphan*/  CLIENT ;

/* Variables and functions */
 int CLNT_CALL (int /*<<< orphan*/ *,int /*<<< orphan*/ ,int /*<<< orphan*/ ,char*,int /*<<< orphan*/ ,char*,struct timeval) ; 
 int /*<<< orphan*/  CLNT_CONTROL (int /*<<< orphan*/ *,int /*<<< orphan*/ ,char*) ; 
 int /*<<< orphan*/  CLNT_DESTROY (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  CLSET_VERS ; 
 scalar_t__ MAX_VERS ; 
 scalar_t__ MIN_VERS ; 
 int /*<<< orphan*/  NULLPROC ; 
 int RPC_PROGVERSMISMATCH ; 
 int RPC_SUCCESS ; 
 int /*<<< orphan*/ * clnt_create (char*,scalar_t__,scalar_t__,char*) ; 
 int /*<<< orphan*/  clnt_geterr (int /*<<< orphan*/ *,struct rpc_err*) ; 
 int /*<<< orphan*/  clnt_pcreateerror (char*) ; 
 int /*<<< orphan*/ * clnt_tp_create (char*,scalar_t__,scalar_t__,struct netconfig*) ; 
 int /*<<< orphan*/  errx (int,char*,char*) ; 
 int /*<<< orphan*/  exit (int) ; 
 struct netconfig* getnetconfigent (char*) ; 
 scalar_t__ getprognum (char*) ; 
 scalar_t__ getvers (char*) ; 
 scalar_t__ pstatus (int /*<<< orphan*/ *,scalar_t__,scalar_t__) ; 
 int /*<<< orphan*/  usage () ; 
 scalar_t__ xdr_void ; 

__attribute__((used)) static void
progping(char *netid, int argc, char **argv)
{
	CLIENT *client;
	struct timeval to;
	enum clnt_stat rpc_stat;
	u_long prognum, versnum, minvers, maxvers;
	struct rpc_err rpcerr;
	int failure = 0;
	struct netconfig *nconf;

	if (argc < 2 || argc > 3 || (netid == NULL))
		usage();
	prognum = getprognum(argv[1]);
	if (argc == 2) { /* Version number not known */
		/*
		 * A call to version 0 should fail with a program/version
		 * mismatch, and give us the range of versions supported.
		 */
		versnum = MIN_VERS;
	} else {
		versnum = getvers(argv[2]);
	}
	if (netid) {
		nconf = getnetconfigent(netid);
		if (nconf == (struct netconfig *)NULL)
			errx(1, "could not find %s", netid);
		client = clnt_tp_create(argv[0], prognum, versnum, nconf);
	} else {
		client = clnt_create(argv[0], prognum, versnum, "NETPATH");
	}
	if (client == (CLIENT *)NULL) {
		clnt_pcreateerror("rpcinfo");
		exit(1);
	}
	to.tv_sec = 10;
	to.tv_usec = 0;
	rpc_stat = CLNT_CALL(client, NULLPROC, (xdrproc_t) xdr_void,
			(char *)NULL, (xdrproc_t) xdr_void,
			(char *)NULL, to);
	if (argc == 3) {
		/* Version number was known */
		if (pstatus(client, prognum, versnum) < 0)
			failure = 1;
		(void) CLNT_DESTROY(client);
		if (failure)
			exit(1);
		return;
	}
	/* Version number not known */
	if (rpc_stat == RPC_PROGVERSMISMATCH) {
		clnt_geterr(client, &rpcerr);
		minvers = rpcerr.re_vers.low;
		maxvers = rpcerr.re_vers.high;
	} else if (rpc_stat == RPC_SUCCESS) {
		/*
		 * Oh dear, it DOES support version 0.
		 * Let's try version MAX_VERS.
		 */
		versnum = MAX_VERS;
		(void) CLNT_CONTROL(client, CLSET_VERS, (char *)&versnum);
		rpc_stat = CLNT_CALL(client, NULLPROC,
				(xdrproc_t) xdr_void, (char *)NULL,
				(xdrproc_t)  xdr_void, (char *)NULL, to);
		if (rpc_stat == RPC_PROGVERSMISMATCH) {
			clnt_geterr(client, &rpcerr);
			minvers = rpcerr.re_vers.low;
			maxvers = rpcerr.re_vers.high;
		} else if (rpc_stat == RPC_SUCCESS) {
			/*
			 * It also supports version MAX_VERS.
			 * Looks like we have a wise guy.
			 * OK, we give them information on all
			 * 4 billion versions they support...
			 */
			minvers = 0;
			maxvers = MAX_VERS;
		} else {
			(void) pstatus(client, prognum, MAX_VERS);
			exit(1);
		}
	} else {
		(void) pstatus(client, prognum, (u_long)0);
		exit(1);
	}
	for (versnum = minvers; versnum <= maxvers; versnum++) {
		(void) CLNT_CONTROL(client, CLSET_VERS, (char *)&versnum);
		rpc_stat = CLNT_CALL(client, NULLPROC, (xdrproc_t) xdr_void,
					(char *)NULL, (xdrproc_t) xdr_void,
					(char *)NULL, to);
		if (pstatus(client, prognum, versnum) < 0)
				failure = 1;
	}
	(void) CLNT_DESTROY(client);
	if (failure)
		exit(1);
	return;
}