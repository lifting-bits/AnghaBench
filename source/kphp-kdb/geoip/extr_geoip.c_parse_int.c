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

/* Variables and functions */
 int /*<<< orphan*/  assert (int) ; 
 char* buff ; 
 int /*<<< orphan*/  mode ; 
 size_t parse_pos ; 
 int sscanf (char*,char*,int*,int*) ; 

unsigned parse_int (void) {
  if (buff[parse_pos] == ',') {
    parse_pos ++;
  }
  int a, x;
  if (!mode) {
    assert (sscanf (buff + parse_pos, "\"%u\"%n", &a, &x) == 1);
  } else {
    assert (sscanf (buff + parse_pos, "%u%n", &a, &x) == 1);
  }
  parse_pos += x;
  assert (!buff[parse_pos] || buff[parse_pos] == ',' || buff[parse_pos] == 10 || buff[parse_pos] == 13);
  return a;
}