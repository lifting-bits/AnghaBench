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
typedef  int /*<<< orphan*/  Node ;

/* Variables and functions */
 int /*<<< orphan*/ * binop (char,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  conv (int /*<<< orphan*/ *) ; 
 scalar_t__ next_token (char) ; 
 int /*<<< orphan*/ * read_multiplicative_expr () ; 

__attribute__((used)) static Node *read_additive_expr() {
    Node *node = read_multiplicative_expr();
    for (;;) {
        if      (next_token('+')) node = binop('+', conv(node), conv(read_multiplicative_expr()));
        else if (next_token('-')) node = binop('-', conv(node), conv(read_multiplicative_expr()));
        else    return node;
    }
}