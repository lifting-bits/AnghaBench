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
struct ar8xxx_priv {int dummy; } ;

/* Variables and functions */
 int /*<<< orphan*/  __ar8216_init_port (struct ar8xxx_priv*,int,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  ar8xxx_has_gige (struct ar8xxx_priv*) ; 
 int /*<<< orphan*/  chip_is_ar8316 (struct ar8xxx_priv*) ; 

__attribute__((used)) static void
ar8216_init_port(struct ar8xxx_priv *priv, int port)
{
	__ar8216_init_port(priv, port, ar8xxx_has_gige(priv),
			   chip_is_ar8316(priv));
}