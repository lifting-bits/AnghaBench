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
struct stat {int dummy; } ;
typedef  int pid_t ;
typedef  int /*<<< orphan*/  cap_rights_t ;

/* Variables and functions */
 int /*<<< orphan*/  CAP_READ ; 
 int /*<<< orphan*/  CAP_SEEK ; 
 int /*<<< orphan*/  CAP_WRITE ; 
 int ECAPMODE ; 
 int /*<<< orphan*/  O_RDONLY ; 
 int /*<<< orphan*/  SIGCHLD ; 
 int /*<<< orphan*/  SIGKILL ; 
 int /*<<< orphan*/  STDOUT_FILENO ; 
 int /*<<< orphan*/  WNOHANG ; 
 int atoi (char*) ; 
 int cap_enter () ; 
 int cap_getmode (unsigned int*) ; 
 int /*<<< orphan*/  cap_rights_describe (int /*<<< orphan*/ *,char*) ; 
 int cap_rights_get (int,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  cap_rights_init (int /*<<< orphan*/ *,int /*<<< orphan*/ ,...) ; 
 int cap_rights_limit (int,int /*<<< orphan*/ *) ; 
 int dup (int /*<<< orphan*/ ) ; 
 int errno ; 
 int /*<<< orphan*/  exit (int /*<<< orphan*/ ) ; 
 int fexecve (int,char**,char**) ; 
 int fork () ; 
 int /*<<< orphan*/  fprintf (int /*<<< orphan*/ ,char*,...) ; 
 int fstat (int,struct stat*) ; 
 int getpid_ () ; 
 int getppid () ; 
 int /*<<< orphan*/  handle_signal ; 
 int open (char*,int /*<<< orphan*/ ) ; 
 int pdfork (int*,int /*<<< orphan*/ ) ; 
 int pdgetpid (int,int*) ; 
 int pdkill (int,int /*<<< orphan*/ ) ; 
 scalar_t__ seen_sigchld ; 
 int /*<<< orphan*/  signal (int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  sleep (int) ; 
 int /*<<< orphan*/  stderr ; 
 char* strerror (int) ; 
 int /*<<< orphan*/  usleep (int) ; 
 int wait4 (int,int*,int /*<<< orphan*/ ,int /*<<< orphan*/ *) ; 

int main(int argc, char *argv[]) {
  signal(SIGCHLD, handle_signal);
  int lifetime = 4; /* seconds */
  if (1 < argc) {
    lifetime = atoi(argv[1]);
  }

  /* cap_rights_limit() available? */
  cap_rights_t r_rws;
  cap_rights_init(&r_rws, CAP_READ, CAP_WRITE, CAP_SEEK);
  int cap_fd = dup(STDOUT_FILENO);
  int rc = cap_rights_limit(cap_fd, &r_rws);
  fprintf(stderr, "[%d] cap_fd=%d\n", getpid_(), cap_fd);
  if (rc < 0) fprintf(stderr, "*** cap_rights_limit() failed: errno=%d %s\n", errno, strerror(errno));

  /* cap_rights_get() available? */
  cap_rights_t rights;
  cap_rights_init(&rights, 0);
  rc = cap_rights_get(cap_fd, &rights);
  char buffer[256];
  cap_rights_describe(&rights, buffer);
  fprintf(stderr, "[%d] cap_rights_get(cap_fd=%d) rc=%d rights=%s\n", getpid_(), cap_fd, rc, buffer);
  if (rc < 0) fprintf(stderr, "*** cap_rights_get() failed: errno=%d %s\n", errno, strerror(errno));

  /* fstat() policed? */
  struct stat buf;
  rc = fstat(cap_fd, &buf);
  fprintf(stderr, "[%d] fstat(cap_fd=%d) rc=%d errno=%d\n", getpid_(), cap_fd, rc, errno);
  if (rc != -1) fprintf(stderr, "*** fstat() unexpectedly succeeded\n");

  /* pdfork() available? */
  int pd = -1;
  rc = pdfork(&pd, 0);
  if (rc < 0) fprintf(stderr, "*** pdfork() failed: errno=%d %s\n", errno, strerror(errno));

  if (rc == 0) { /* child */
    int count = 0;
    while (count < 20) {
      fprintf(stderr, "  [%d] child alive, parent is ppid=%d\n", getpid_(), getppid());
      sleep(1);
    }
    fprintf(stderr, "  [%d] child exit(0)\n", getpid_());
    exit(0);
  }
  fprintf(stderr, "[%d] pdfork() rc=%d pd=%d\n", getpid_(), rc, pd);

  /* pdgetpid() available? */
  pid_t actual_pid = rc;
  pid_t got_pid = -1;
  rc = pdgetpid(pd, &got_pid);
  if (rc < 0) fprintf(stderr, "*** pdgetpid(pd=%d) failed: errno=%d %s\n", pd, errno, strerror(errno));
  fprintf(stderr, "[%d] pdgetpid(pd=%d)=%d, pdfork returned %d\n", getpid_(), pd, got_pid, actual_pid);

  sleep(lifetime);

  /* pdkill() available? */
  rc = pdkill(pd, SIGKILL);
  fprintf(stderr, "[%d] pdkill(pd=%d, SIGKILL) -> rc=%d\n", getpid_(), pd, rc);
  if (rc < 0) fprintf(stderr, "*** pdkill() failed: errno=%d %s\n", errno, strerror(errno));
  usleep(50000);  /* Allow time for death and signals */

  /* Death of a pdforked child should be invisible */
  if (seen_sigchld) fprintf(stderr, "*** SIGCHLD emitted\n");
  int status;
  rc = wait4(-1, &status, WNOHANG, NULL);
  if (rc > 0) fprintf(stderr, "*** wait4(-1, ...) unexpectedly found child %d\n", rc);

  fprintf(stderr, "[%d] forking off a child process to check cap_enter()\n", getpid_());
  pid_t child = fork();
  if (child == 0) { /* child */
    /* cap_getmode() / cap_enter() available? */
    unsigned int cap_mode = -1;
    rc = cap_getmode(&cap_mode);
    fprintf(stderr, "  [%d] cap_getmode() -> rc=%d, cap_mode=%d\n", getpid_(), rc, cap_mode);
    if (rc < 0) fprintf(stderr, "*** cap_getmode() failed: errno=%d %s\n", errno, strerror(errno));

    rc = cap_enter();
    fprintf(stderr, "  [%d] cap_enter() -> rc=%d\n", getpid_(), rc);
    if (rc < 0) fprintf(stderr, "*** cap_enter() failed: errno=%d %s\n", errno, strerror(errno));

    rc = cap_getmode(&cap_mode);
    fprintf(stderr, "  [%d] cap_getmode() -> rc=%d, cap_mode=%d\n", getpid_(), rc, cap_mode);
    if (rc < 0) fprintf(stderr, "*** cap_getmode() failed: errno=%d %s\n", errno, strerror(errno));

    /* open disallowed? */
    rc = open("/etc/passwd", O_RDONLY);
    fprintf(stderr, "  [%d] open('/etc/passwd') -> rc=%d, errno=%d\n", getpid_(), rc, errno);
    if (rc != -1) fprintf(stderr, "*** open() unexpectedly succeeded\n");
#ifdef ECAPMODE
    if (errno != ECAPMODE) fprintf(stderr, "*** open() failed with errno %d not ECAPMODE\n", errno);
#endif
    exit(0);
  }
  rc = wait4(child, &status, 0, NULL);
  fprintf(stderr, "[%d] child %d exited with status %x\n", getpid_(), child, status);

  /* fexecve() available? */
  char* argv_pass[] = {(char*)"/bin/ls", "-l", "smoketest", NULL};
  char* null_envp[] = {NULL};
  int ls_bin = open("/bin/ls", O_RDONLY);
  fprintf(stderr, "[%d] about to fexecve('/bin/ls', '-l', 'smoketest')\n", getpid_());
  rc = fexecve(ls_bin, argv_pass, null_envp);
  /* should never reach here */
  fprintf(stderr, "*** fexecve(fd=%d) failed: rc=%d errno=%d %s\n", ls_bin, rc, errno, strerror(errno));

  return 0;
}