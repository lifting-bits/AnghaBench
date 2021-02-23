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
struct target {int /*<<< orphan*/  t_ports; int /*<<< orphan*/  t_name; } ;
struct pport {int /*<<< orphan*/  pp_ports; int /*<<< orphan*/  pp_name; } ;
struct port {char* p_name; struct pport* p_pport; struct target* p_target; struct conf* p_conf; } ;
struct conf {int /*<<< orphan*/  conf_ports; } ;

/* Variables and functions */
 int /*<<< orphan*/  TAILQ_INSERT_TAIL (int /*<<< orphan*/ *,struct port*,int /*<<< orphan*/ ) ; 
 int asprintf (char**,char*,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 struct port* calloc (int,int) ; 
 int /*<<< orphan*/  free (char*) ; 
 int /*<<< orphan*/  log_err (int,char*) ; 
 int /*<<< orphan*/  log_warnx (char*,char*) ; 
 int /*<<< orphan*/  p_next ; 
 int /*<<< orphan*/  p_pps ; 
 int /*<<< orphan*/  p_ts ; 
 int /*<<< orphan*/ * port_find (struct conf*,char*) ; 

struct port *
port_new_pp(struct conf *conf, struct target *target, struct pport *pp)
{
	struct port *port;
	char *name;
	int ret;

	ret = asprintf(&name, "%s-%s", pp->pp_name, target->t_name);
	if (ret <= 0)
		log_err(1, "asprintf");
	if (port_find(conf, name) != NULL) {
		log_warnx("duplicate port \"%s\"", name);
		free(name);
		return (NULL);
	}
	port = calloc(1, sizeof(*port));
	if (port == NULL)
		log_err(1, "calloc");
	port->p_conf = conf;
	port->p_name = name;
	TAILQ_INSERT_TAIL(&conf->conf_ports, port, p_next);
	TAILQ_INSERT_TAIL(&target->t_ports, port, p_ts);
	port->p_target = target;
	TAILQ_INSERT_TAIL(&pp->pp_ports, port, p_pps);
	port->p_pport = pp;
	return (port);
}